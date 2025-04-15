#include <iostream>
#include <list>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node()
    {
        this->val = 0;
        this->next = nullptr;
    }
    Node(int value)
    {
        this->val = value;
        this->next = nullptr;
    }
    Node(int value, Node *node)
    {
        this->val = value;
        this->next = node;
    }
};

class Solution
{
public:
    void printList(Node *node)
    {
        if (node == nullptr)
            return;

        cout << node->val << " ";
        printList(node->next);
    }
};

int main()
{
    Node *new_node = new Node(10);
    new_node->next = new Node(11);
    new_node->next->next = new Node(12);
    new_node->next->next->next = new Node(13);

    Solution sol;
    cout << "The linked list is" << endl;
    sol.printList(new_node);
}
