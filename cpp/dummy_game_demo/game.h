#ifndef GAME_H
#define GAME_H
#include <unordered_set>
#include <vector>
#include <unordered_set>
#include <string_view>
#include <memory>
#include <mutex>
#include "client.h"

class Game{
public:
    Game(){}

    void addPlayer(std::shared_ptr<Client> clientPtr);

    void onGetItem(std::shared_ptr<Client> clientPtr, std::string_view name, int count);

    void onDropItem(std::shared_ptr<Client> clientPtr, std::string_view name, int count);

    bool onSwitchItem(std::shared_ptr<Client> from, std::shared_ptr<Client> to, std::string_view name, int count);

    void onQuit(std::shared_ptr<Client> clientPtr);

    int clientCount();

private:
    std::unordered_set<std::shared_ptr<Client>> players_;
    std::mutex mutex_;
};
#endif