#include <iostream>
#include "game.h"
#include "client.h"

void Game::addPlayer(std::shared_ptr<Client> clientPtr)
{
    std::lock_guard lk(mutex_);
    players_.insert(clientPtr);
}

void Game::onGetItem(std::shared_ptr<Client> clientPtr, std::string_view name, int count)
{
    if(clientPtr== nullptr || count <=0 || name.empty())
    {
        return;
    }
    clientPtr->addItem(name, count);
}

void Game::onDropItem(std::shared_ptr<Client> clientPtr, std::string_view name, int count)
{
    if (clientPtr== nullptr || count <=0 || name.empty())
    {
        return;
    }
    clientPtr->removeItem(name, count);
}

bool Game::onSwitchItem(std::shared_ptr<Client> clientFromPtr, std::shared_ptr<Client> clientToPtr, std::string_view name, int count)
{
    if (!clientFromPtr|| !clientToPtr || name.empty() || count <=0)
    {
        return false;
    }

    // An alternative way
    // std::lock(clientFromPtr->getMutex(), clientToPtr->getMutex());
    // std::lock_guard lk(clientFromPtr->getMutex(),std::adopt_lock);
    // std::lock_guard lk2(clientToPtr->getMutex(),std::adopt_lock);

    // Another alternative way
    // std::unique_lock lock1(clientFromPtr->getMutex(),std::defer_lock);
    // std::unique_lock lock2(clientToPtr->getMutex(),std::defer_lock);
    // std::lock(lock1, lock2);

    // recommended way for c++17 and later
    std::scoped_lock lockAll(clientFromPtr->getMutex(), clientToPtr->getMutex());

    int available = clientFromPtr->itemCountImpl(name);

    if (available < count)
        return false;

    if (clientFromPtr->removeItemImpl(name, count) != -1)
    {
        clientToPtr->addItemImpl(name, count);
        return true;
    }
    return false;
}

void Game::onQuit(std::shared_ptr<Client> clientPtr)
{
    std::lock_guard lk(mutex_);
    players_.erase(clientPtr);
}

int Game::clientCount()
{
    std::lock_guard lk(mutex_);
    return players_.size();
}