#include <iostream>
#include <list>
#include <unordered_map>
#include <iterator>

class lru
{
public:
    lru(int cap) : capacity_(cap) {}

    void put(int key, int value)
    {
        if (auto it = index_.find(key); it != index_.end())
        {
            data_.erase(it->second);
            index_.erase(key);
            
        }
        else
        {
            if (data_.size() == capacity_)
            {
                auto tbd = data_.front();
                data_.pop_front();
                index_.erase(tbd.first);
            }
        }
        data_.emplace_back(key, value);
        index_[key] = std::next(data_.end(), -1);
    }

    int get(int key)
    {
        auto it = index_.find(key);
        if (it == index_.end())
        {
            return INT_MIN;
        }

        auto value = it->second->second;
        data_.erase(it->second);
        index_.erase(key);
        data_.emplace_back(key, value);
        index_[key] = std::next(data_.end(), -1);
        return value;
    }

    bool exist(int key) const
    {
        if (index_.find(key) == index_.end())
        {
            return false;
        }
        return true;
    }

    void print() const 
    {
        for (auto &&i : data_)
        {
            std::cout << i.first << "," << i.second << "\n";
        }
        std::cout << "\n";
    }

private:
    std::list<std::pair<int, int>> data_;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> index_;
    int capacity_;
};

int main()
{
    lru l(4);
    l.put(1, 1);
    l.put(2, 4);
    l.put(3, 6);
    l.put(4, 8);
    l.put(5, 10);
    l.print();

    l.put(2, 5);
    l.print();
    auto r = l.get(3);
    l.print();

    return 0;
}