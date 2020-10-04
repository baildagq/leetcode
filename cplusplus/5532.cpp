#include "./utils.h"



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if (root == nullptr) return true;
        int level = 0;
        vector<TreeNode*> stack{root};
        while (stack.size() != 0) {
            vector<TreeNode*> newstack;
            if (level == 0) {
                if (stack[0]->val % 2 != 1) return false;
                for (int i = 1; i < (int)stack.size(); i++) {
                    if (stack[i]->val % 2 != 1 || stack[i]->val <= stack[i-1]->val) return false;
                }
            } else {
                if (stack[0]->val % 2 != 0) return false;
                for (int i = 1; i < (int)stack.size(); i++) {
                    if (stack[i]->val % 2 != 0 || stack[i]->val >= stack[i-1]->val) return false;
                }
            }
            for (auto node : stack) {
                if (node->left != nullptr) newstack.push_back(node->left);
                if (node->right!= nullptr) newstack.push_back(node->right);
            }
            stack = newstack;
        }
        return true;
    }
};


int main(int argc, const char** argv)
{
    return 0;
}
