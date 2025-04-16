// This is the solution to the leetcode problem where we add two linkedlist and treat as number

#include <iostream>
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
    Node(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
    Node(int val, Node *next)
    {
        this->val = val;
        this->next = next;
    }
};
class Solution
{
public:
    Node *addTwoNumbers(Node *n1, Node *n2)
    {
        return createSum(n1, n2, 0);
    }
    Node *createSum(Node *n1, Node *n2, int carry)
    {
        if (n1 == nullptr && n2 == nullptr && carry == 0)
            return nullptr;
        int val1 = n1 == nullptr ? 0 : n1->val;
        int val2 = n2 == nullptr ? 0 : n2->val;

        int sum = val1 + val2 + carry;
        int new_val = sum % 10;
        int new_carry = sum / 10;

        Node *result_node = new Node(new_val);
        result_node->next = createSum(n1->next, n2->next, new_carry);
        return result_node;
    }

    void printList(Node *list)
    {
        while (list != nullptr)
        {
            cout << list->val << " ";
            list = list->next;
        }
    }
};

int main()
{
    Node *n1 = new Node(2);
    Node *n2 = new Node(5);

    n1->next = new Node(4);
    n2->next = new Node(6);
    n1->next->next = new Node(3);
    n2->next->next = new Node(4);

    Solution sol;

    Node *sumNode = sol.addTwoNumbers(n1, n2);
    sol.printList(sumNode);
}