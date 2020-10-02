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
    int getDepth(string s, int& idx) {
        int res = 0;
        while (idx < (int)s.length() && s[idx] == '-') {
            res += 1;
            idx += 1;
        }
        return res;
    }

    int getNumber(string s, int& idx) {
        int res = 0;
        while (idx < (int)s.length() && s[idx] != '-') {
            res = res * 10 + s[idx] - '0';
            idx += 1;
        }
        return res;
    }

    void makeTree(string S, TreeNode* root, int depth, int& idx) {
        // 返回值为
        int record = idx;
        int dl = getDepth(S, idx);
        if (dl == depth) {
            int nl = getNumber(S, idx);
            root->left = new TreeNode(nl);
            makeTree(S, root->left, depth+1, idx);
        } else {
            idx = record;
            return;
        }
        
        record = idx;
        int dr = getDepth(S, idx);
        if (dr == depth) {
            int nr = getNumber(S, idx);
            root->right = new TreeNode(nr);
            makeTree(S, root->right, depth+1, idx);
        } else {
            idx = record;
            return;
        }
    }
    
    TreeNode* recoverFromPreorder(string S) {
        int idx = 0;
        int num = getNumber(S, idx);
        TreeNode* res = new TreeNode(num);
        makeTree(S, res, 1, idx);
        return res;
    }
};



int main(int argc, const char** argv)
{
    string s = "1-2--3--4-5--6--7";
    TreeNode* res = Solution().recoverFromPreorder(s);
    printTree(res);
    return 0;
}
