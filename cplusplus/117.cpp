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
    void make(Node* root, Node* parent)
    {
        if (parent) { //跳过根节点
            if (root == parent->left && parent->right != nullptr) {
                root->next = parent->right;
            } else {
                // 需要到异父节点中寻找
                while(parent->next) {
                    parent = parent->next;
                    if (parent->left) {
                        root->next = parent->left;
                        break;
                    }
                    if (parent->right) {
                        root->next = parent->right;
                        break;
                    }
                }
            }
        }
        if (root->right) {
            make(root->right, root);
        }
        if (root->left) {
            make(root->left, root);
        }
    }
    Node* connect(Node* root)
    {
        if (root == nullptr)
            return root;
        make(root, nullptr);
        return root;
    }
};

int main(int argc, const char** argv)
{
    vector<int> list = { 2, 3, -2, 4 };
    return 0;
}
