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



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void inorderTransversal(TreeNode* root, vector<int>& nums) {
        if (root == nullptr) {
            return;
        }
        inorderTransversal(root->left, nums);
        nums.push_back(root->val);
        inorderTransversal(root->right, nums);
    }
    void reverseInorderTransversal(TreeNode* root, vector<int>& nums, int& sum) {
        if (root == nullptr) {
            return;
        }
        reverseInorderTransversal(root->right, nums, sum);
        sum += nums.back();
        nums.pop_back();
        root->val = sum;
        reverseInorderTransversal(root->left, nums, sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> nums;
        int sum = 0;
        inorderTransversal(root, nums);
        reverseInorderTransversal(root, nums, sum);
        return root;
    }
};


int main(int argc, const char** argv) {
    vector<int> list = {1,2,3,4};
    printVector(list);
    return 0;
}
