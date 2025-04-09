#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Node
{
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
{
public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;
        unordered_map<int, Node *> visited;
        return (clone_node(node, visited));
    }
    Node *clone_node(Node *node, unordered_map<int, Node *> &visited)

    // We use &visited and not just visited so that the value of the hashmap remains constant accross the recursive calls and the changes are made in the same visited hashmap. It is very necessary that the visited hashmap is consistent accross all function calls.
    {
        Node *new_node = new Node(node->val);
        visited.insert({node->val, new_node});

        for (Node *n : node->neighbors)
        {
            auto it = visited.find(n->val);
            // if nothing is found then the iterator it will point at visited.end()
            if (it == visited.end())
            {
                // not visited
                Node *cn = clone_node(n, visited);
                new_node->neighbors.push_back(cn);
            }
            else
            {
                new_node->neighbors.push_back(it->second);
            }
        }
        return new_node;
    }
    void printGraph(Node *node)
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
            cout << "Node " << current->val << " -> ";
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
    // Create a sample graph
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);

    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};

    cout << "Original Graph:" << endl;

    Solution solution;
    solution.printGraph(node1);
    Node *clonedGraph = solution.cloneGraph(node1);

    cout << "\nCloned Graph:" << endl;
    solution.printGraph(clonedGraph);

    return 0;
}