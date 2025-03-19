#ifndef CLIENT_H
#define CLIENT_H
#include <mutex>
#include <unordered_map>


class Client{
public:
    Client(std::string name):name_(name){}

    int itemSize();

    int itemCount(std::string_view name);

    int itemCountImpl(std::string_view name);

    void addItem(std::string_view name, int amount);

    void addItemImpl(std::string_view name, int amount);

    int removeItem(std::string_view name, int amount);

    int removeItemImpl(std::string_view name, int amount);

    std::mutex& getMutex();

    std::string getName() const 
    {
        return name_;
    }

private:
    std::mutex mutex_;
    std::unordered_map<std::string, int> items_;
    std::string name_;
};
#endif