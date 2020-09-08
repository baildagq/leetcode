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


class Solution {
public:
    TreeNode* convertBiNode(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode* guard = new TreeNode(0);
        TreeNode* tail = guard;
        // make left
        if (root->left != nullptr) {
            tail->right = convertBiNode(root->left);
            while(tail->right != nullptr) {
                tail = tail->right;
            }
            root->left = nullptr;
        }
        // make root
        tail->right = root;
        printf("roo-val: %d\n", root->val);
        tail = tail->right;
        // make right
        if (root->right != nullptr) {
            tail->right = convertBiNode(root->right);        
        }
        return guard->right;
    }
};


int main(int argc, const char** argv) {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->left->left = new TreeNode(0);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    printTree(root);
    printf("\n");
    TreeNode* newres = Solution().convertBiNode(root);
    printTree(root);
    // printf("\n");
    return 0;
}
