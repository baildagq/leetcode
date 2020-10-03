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
    int res = INT_MIN;
public:
    int traverse(TreeNode* root) {
        if (root == nullptr) return 0;
        int ls = traverse(root->left);
        int rs = traverse(root->right);
        // 令当前节点（+下属1/2个分支）做为答案路径
        int val = max(root->val, root->val + max(max(ls, rs), ls + rs));
        res = max(res, val);
        // 令当前节点(+下属1个分支)做为路径的一部分
        return max(root->val, root->val + max(ls, rs));
    }
    int maxPathSum(TreeNode* root) {
        traverse(root);
        return res;
    }
};



int main(int argc, const char** argv)
{
    return 0;
}
