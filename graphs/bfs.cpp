#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class Node
{ // This class is the node class for defining the data type of a graph.
public:
    int val;
    vector<Node *> neighbors;

    Node()
    {
        this->val = 0;
        this->neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        this->val = _val;
        this->neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        this->val = _val;
        this->neighbors = _neighbors;
    }
};

class Solution
{ // bfs algorithm to traverse in the graph. The bfs algorith uses the queue approach.
public:
    void bfs(Node *node)
    {
        if (!node)
            return;

        unordered_map<int, bool> visited;

        queue<Node *> q;
        q.push(node);
        visited[node->val] = true;
        while (!q.empty())
        {
            Node *current = q.front();
            q.pop();
            cout << current->val << "->";
            for (Node *neighbor : current->neighbors)
            {
                cout << neighbor->val << " ";
                if (!visited[neighbor->val])
                {
                    visited[neighbor->val] = true;
                    q.push(neighbor);
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);

    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};

    Solution sol;
    sol.bfs(node1);
}