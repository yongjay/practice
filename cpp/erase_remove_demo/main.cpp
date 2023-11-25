#include <iostream>
#include <vector>
#include <string>

int main(int, char**){
    std::vector<int> vec{2, 4, 2, 4, 2, 1, 2, 4, 2, 2, 5, 6, 4};
    std::string str{"wwwwwwwwwwwwwwwwhat"};

    vec.erase(std::remove(vec.begin(), vec.end(), 2), vec.end());
    str.erase(std::remove(str.begin(), str.end(), 'w'), str.end());

    for (const auto &v : vec)
    {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    std::cout << str << std::endl;
}
