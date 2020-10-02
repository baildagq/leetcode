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
    TreeNode* invertTree(TreeNode* root) {
        if (root != nullptr) {
            TreeNode* tmp = root->left;
            root->left = root->right;
            root->right = tmp;
            invertTree(root->left);
            invertTree(root->right);
        }
		return root;
    }
};



int main(int argc, const char** argv)
{
    // vector<int> list = {2,3,-2,4};
    // TreeNode* root = makeTree(list);
    // TreeNode* res = Solution.invertTree(root);
    // printTree(res);
    return 0;
}
