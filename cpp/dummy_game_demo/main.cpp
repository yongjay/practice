/*
模拟一个游戏服务器的简单逻辑,主要有两个类，客户端类（玩家）和游戏类（服务器）
1、玩家有不同的装备，每个装备有不同的个数,玩家可以捡装备也可以丢装备，或转移装备给其他人；
2、服务器需要管理所有的玩家，并处理玩家不同的动作，捡装备、丢装备等；
3、注意这些动作需要是线程安全的；
*/

#include <iostream>
#include <thread>
#include <memory>
#include <mutex>
#include <random> 
#include "client.h"
#include "game.h"

std::mutex mutex_;
void actions(Game *game, std::shared_ptr<Client> clientPtr, std::shared_ptr<Client> clientPtr2)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 10);
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        int randomNum = dist(gen);
        game->onSwitchItem(clientPtr, clientPtr2, "sword", randomNum);
        {
            std::lock_guard lk(mutex_);
            std::cout << "switch: " << randomNum << " form " << clientPtr->getName() << " to " << clientPtr2->getName() << "\n";
            std::cout << clientPtr->getName() <<":"<< clientPtr->itemCount("sword") << "\n";
            std::cout << clientPtr2->getName() <<":"<< clientPtr2->itemCount("sword") << "\n";
        }
    }
}

int main()
{
    // multithread test
    Game* game = new Game();
    auto player1 = std::make_shared<Client>("player1");
    auto player2 = std::make_shared<Client>("player2");

    game->addPlayer(player1);
    game->addPlayer(player2);

    game->onGetItem(player1, "sword", 10);
    game->onGetItem(player2, "sword", 10);

    std::thread t1(actions, game, player1,player2);
    std::thread t2(actions, game, player2,player1);
    t1.join();
    t2.join();
    return 0;
}