#include "./utils.h"

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node()
        : val(0)
        , left(NULL)
        , right(NULL)
        , next(NULL)
    {
    }

    Node(int _val)
        : val(_val)
        , left(NULL)
        , right(NULL)
        , next(NULL)
    {
    }

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val)
        , left(_left)
        , right(_right)
        , next(_next)
    {
    }
};

class Solution {
public:
    Node* connect(Node* root)
    {
        if (root == nullptr)
            return root;
        vector<Node*> stack;
        stack.push_back(root);
        while (stack.size() != 0) {
            vector<Node*> newStack;
            for (int i = 0; i < stack.size() - 1; i++) {
                stack[i]->next = stack[i + 1];
            }
            for (auto node : stack) {
                if (node->left != nullptr)
                    newStack.push_back(node->left);
                if (node->right != nullptr)
                    newStack.push_back(node->right);
            }
            stack = newStack;
        }
        return root;
    }
};

int main(int argc, const char** argv)
{
    vector<int> list = { 2, 3, -2, 4 };
    return 0;
}
