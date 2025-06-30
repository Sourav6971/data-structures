#include <vector>
#include <unordered_set>
#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int value;
    vector<Node *> neighbors;

    Node()
    {
        this->value = 0;
    }

    Node(int val)
    {
        this->value = val;
    }
    Node(int val, vector<Node *> neighbors)
    {
        this->value = val;
        this->neighbors = neighbors;
    }
};
class Solution
{
public:
    void DFS(Node *root)
    {

        if (!root)
            return;
        vector<Node *> neighbors = root->neighbors;
        unordered_set<int> visited;
        visited.insert(root->value);
        cout << root->value;

        for (Node *&neighbor : neighbors)
        {
            if (visited.count(neighbor->value))
                continue;
            visited.insert(neighbor->value);
            DFS(neighbor);
        }
    }
    void iterativeDfs(Node *root)
    {
        if (!root)
        {
            return;
        }
        stack<Node *> container;
        container.push(root);
        cout << root->value << " ";
        unordered_set<Node *> visited;
    }
};

int main()
{
    Solution sol;
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);
    Node *n7 = new Node(7);

    n1->neighbors.push_back(n2);
    n1->neighbors.push_back(n3);
    n1->neighbors.push_back(n7);
    n2->neighbors.push_back(n6);
    n3->neighbors.push_back(n4);
    n4->neighbors.push_back(n5);

    sol.iterativeDfs(n1);
}
