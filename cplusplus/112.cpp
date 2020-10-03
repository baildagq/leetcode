#include "./utils.h"



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool judge(TreeNode* root, int sum, int target) {
        if (root == nullptr) return false;
        sum += root->val;
        if (sum == target && root->left == nullptr && root->right == nullptr) return true;
        if (judge(root->left, sum, target)) return true;
        if (judge(root->right, sum, target)) return true;
        return false;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        return judge(root, 0, sum);
    }
};


int main(int argc, const char** argv)
{
    return 0;
}
