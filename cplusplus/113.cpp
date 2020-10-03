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
    vector<vector<int>> res;
    vector<int> item;
public:
    void traverse(TreeNode* root, int sum, int target) {
        if (root == nullptr) return;
        sum += root->val;
        item.push_back(root->val);
        if (sum == target && root->left == nullptr && root->right == nullptr) {
            res.push_back(item);
        }
        traverse(root->left, sum, target);
        traverse(root->right, sum, target);
        item.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        traverse(root, 0, sum);
        return res;
    }
};


int main(int argc, const char** argv)
{
    return 0;
}
