/*
 * @Author: yongjay yongjaylu@gmail.com
 * @Date: 2024-03-16 09:38:43
 * @LastEditors: yongjay yongjaylu@gmail.com
 * @LastEditTime: 2024-03-16 10:06:58
 * @FilePath: /cpp/AA_demo/algorithm_demo/reverse_list/common.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include <iostream>

struct Node
{
    Node(int v ):value(v),next(nullptr){}
    int value;
    Node *next;
};

void print(Node* head)
{
    while(head!= nullptr)
    {
        std::cout << head->value<<" ";
        head = head->next;
    }
}   


