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
    void build(TreeNode* root, const vector<int>& preorder, int pl, int pr, const vector<int>& inorder, int il, int ir) {
        int target = root->val;

        int len = 0;
        for (int i = il; i < ir && inorder[i] != target; i++) {
            len += 1;
        }
        if (len > 0) {
            root->left = new TreeNode(preorder[pl + 1]);
            build(root->left, preorder, pl + 1, pl + len, inorder, il, il + len - 1);
        }
        if (pl + len + 1 <= pr) {
            root->right = new TreeNode(preorder[pl + len + 1]);
            build(root->right, preorder, pl + len + 1, pr, inorder, il + len + 1, ir);
        }
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return nullptr;
        TreeNode* res = new TreeNode(preorder[0]);
        build(res, preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
        return res;
    }
};


int main(int argc, const char** argv)
{
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* res = Solution().buildTree(preorder, inorder);
    printTree(res);
    return 0;
}
