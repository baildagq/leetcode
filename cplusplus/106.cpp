#include "./utils.h"
#include <climits>

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
    vector<int> inorder;
    vector<int> postorder;
public:
    void build(TreeNode* root, int l1, int r1, int l2, int r2) {
        int target = postorder[r2];
        int len = 0;
        for (int i = l1; i <= r1 && inorder[i] != target; i++) len++;
        if (len > 0) {
            root->left = new TreeNode(postorder[l2 + len - 1]);
            build(root->left, l1, l1 + len - 1, l2, l2 + len - 1);
        }
        if (l2 + len != r2) {
            root->right = new TreeNode(postorder[r2 - 1]);
            build(root->right, l1 + len + 1, r1, l2 + len, r2 - 1);
        }
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        int size = inorder.size();
        if (size == 0) return nullptr;
        this->inorder = inorder;
        this->postorder = postorder;
        TreeNode* res = new TreeNode(postorder[size - 1]);
        build(res, 0, size - 1, 0, size - 1);
        return res;
    }
};

int main(int argc, const char** argv)
{
    vector<int> inorder = { 9, 3, 15, 20, 7 };
    vector<int> postorder = { 3, 9, 20, 15, 7 };
    TreeNode* res = Solution().buildTree(inorder, postorder);
    printTree(res);
    return 0;
}
