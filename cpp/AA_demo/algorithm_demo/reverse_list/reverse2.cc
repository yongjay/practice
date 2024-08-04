/*
 * @Author: yongjay yongjaylu@gmail.com
 * @Date: 2024-03-16 10:20:19
 * @LastEditors: yongjay yongjaylu@gmail.com
 * @LastEditTime: 2024-03-16 10:57:52
 * @FilePath: /cpp/AA_demo/algorithm_demo/reverse_list/reverse2.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include "common.h"


Node* func(Node* head,int left ,int right)
{
    Node *dummy = new Node(-1);
    dummy->next = head;
    Node *pre = dummy;

    for (size_t i = 0; i < left-1; i++) // attention 1
    {
        pre = pre->next;
    }

    Node *rightNode = pre;
    for (size_t i = 0; i < right-left+1; i++) // attention 2
    {
        rightNode = rightNode->next;
    }

    Node *leftNode = pre->next;
    Node *afterRightNode = rightNode->next;

    pre->next = nullptr;
    rightNode->next = nullptr;
    Node *p = nullptr;
    Node *c = leftNode;

    while(c!= nullptr)
    {
        Node *temp = c->next;
        c->next = p;
        p = c;
        c = temp;
    }

    pre->next = p;
    leftNode->next = afterRightNode;

    return dummy->next;
}

int main()
{
    Node *n0 = new Node(0);
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);
    Node *n7 = new Node(7);

    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    auto ret = func(n0, 1, 7);
    print(ret);

    delete n0;
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;
    delete n7;
    return 0;
}