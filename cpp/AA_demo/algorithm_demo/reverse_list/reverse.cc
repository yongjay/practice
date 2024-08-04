#include <iostream>
#include "common.h"

Node *func(Node *head)
{
    Node *pre = nullptr;
    Node *cur = head;
    while (cur != nullptr)
    {
        Node *temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
}

int main()
{
    Node *n0 = new Node(0);
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);

    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    auto ret = func(n0);
    print(ret);

    delete n0;
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    return 0;
}