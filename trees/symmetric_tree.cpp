// Finding whether a binary tree is symmetric or not
#include <iostream>
using namespace std;

struct treeNode
{
    int val;
    treeNode *left;
    treeNode *right;

    treeNode(int x)
    {
        this->val = x;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Solution
{
public:
    bool isSymmetric(treeNode *root)
    {
        if (root == nullptr)
            return true;

        return (areMirror(root->left, root->right));
    }
    bool areMirror(treeNode *r1, treeNode *r2)
    {
        if (!r1 || !r2)
        {
            return (r1 == r2);
        }
        if (r1->val != r2->val)
        {
            return false;
        }
        return (areMirror(r1->left, r2->right) && areMirror(r1->right, r2->left));
    }
};

int main()
{
}