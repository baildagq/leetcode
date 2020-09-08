#include <iostream>
#include <cstdlib>
#include <stack>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <climits>
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
    vector<int> nums;
    int solve(TreeNode* root, bool robbed) {
        /*
         * robbed: indict whether root's father robbed
         */ 
        int res = 0;
        if (root != nullptr) {
            if (robbed){
                res = max(res, solve(root->left, false)+solve(root->right, false));
            } else {
                res = max(res, root->val+solve(root->left, true)+solve(root->right, true));
                res = max(res, solve(root->left, false)+solve(root->right, false));
            }
        }
        return res;
    }
    int rob(TreeNode* root) {
        int res = max(solve(root, true), solve(root, false));
        return res;
    }
};


int main(int argc, const char** argv) {
    vector<int> list = {1,2,3,4};
    printVector(list);
    return 0;
}
