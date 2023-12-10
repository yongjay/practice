#include <iostream>
#include <ranges>
#include <vector>

void print(const std::vector<int>& v)
{
    for (const auto &i : v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main(int, char**){
    std::vector<int> v{1, 4, 2, 4, 3, 2, 4, 3, 24, 5, 6, 4, 3, 0};
    print(v);
    // sort
    std::ranges::sort(v);
    print(v);

    std::cout << "Hello, from ranges_demo!\n";
}
