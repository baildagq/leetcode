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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        vector<TreeNode*> stack;
        set<TreeNode*> visited;
        if (root == nullptr) return res;
        stack.push_back(root);
        while(!stack.empty()) {
            TreeNode* node = stack.back();
            if (visited.find(node) == visited.end()) {
                if (node->right != nullptr) stack.push_back(node->right);
                if (node->left != nullptr) stack.push_back(node->left);
                visited.insert(node);
            } else {
                res.push_back(node->val);
                stack.pop_back();
            }
        }
        return res;
    }
};


int main(int argc, const char** argv)
{
    // vector<int> list = {2,3,-2,4};
    // printf("res: %d\n", Solution().xxx(list));
    return 0;
}
