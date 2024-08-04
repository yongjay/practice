#include <iostream>
#include <vector>
#include <string>

std::string func(const std::string& src,int n)
{
    if (n<2)
    {
        return src;
    }

    int i = 0;
    int flag = -1;
    std::string ret;

    std::vector<std::string> strs(n);
    for (auto &&c : src)
    {
        strs.at(i).push_back(c);
        if (i == 0 || i == n-1)
        {
            flag = -flag;
        }
        i += flag;
    }

    for (auto &&str : strs)
    {
        ret += str;
    }

    return ret;
}

int main()
{
    std::string src{"AB"};
    auto ret = func(src, 1);
    std::cout << ret << "\n";

    return 0;
}

/*
H   O   L
E L W R D
L   O  

output:  HOLELWRDLO
*/