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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        solve(root);
    }
    TreeNode* solve(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = nullptr;
        root->right = solve(left);
        TreeNode* tail = root;
        while (tail->right != nullptr){
            tail = tail->right;
        }
        tail->right = solve(right);
        return root;
    }
};


int main(int argc, const char** argv) {
    vector<int> list = {1,2,3,4};
    printVector(list);
    return 0;
}
