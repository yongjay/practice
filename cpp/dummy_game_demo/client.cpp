#include "client.h"
#include <optional>
#include <iostream>

int Client::itemSize()
{
    // std::lock_guard lk(mutex_);
    return items_.size();
}

int Client::itemCount(std::string_view name)
{
    std::lock_guard lk(mutex_);
    return itemCountImpl(name);
}

int Client::itemCountImpl(std::string_view name)
{
    if (auto it = items_.find(std::string(name)); it != items_.end())
    {
        return it->second;
    }
    return 0;
}

void Client::addItem(std::string_view name, int amount)
{
    if (amount<=0)
    {
        return;
    }

    std::lock_guard lk(mutex_);
    addItemImpl(name, amount);
}

void Client::addItemImpl(std::string_view name, int amount)
{
    items_[std::string(name)] += amount;
}

int Client::removeItem(std::string_view name, int amount)
{
    if (amount <= 0)
        return -1;

    std::lock_guard lk(mutex_);
    removeItemImpl(name, amount);
}

int Client::removeItemImpl(std::string_view name, int amount)
{
    auto it = items_.find(std::string(name));
    if (it == items_.end())
        return -1;

    if (it->second < amount)
        return -1;

    it->second -= amount;
    if (it->second == 0)
    {
        items_.erase(it);
    }
    return amount;
}

std::mutex& Client::getMutex()
{
    return mutex_;
}
