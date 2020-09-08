#include "./utils.h"

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    void dfs(vector<string> &res, string ans, TreeNode *root)
    {
        if (ans != "")
        {
            ans += ("->" + to_string(root->val));
        }
        else
        {
            ans = to_string(root->val);
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            res.push_back(ans);
            return;
        }
        if (root->left != nullptr)
        {
            dfs(res, ans, root->left);
        }
        if (root->right != nullptr)
        {
            dfs(res, ans, root->right);
        }
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> res;
        if (root == nullptr)
            return res;
        dfs(res, "", root);
        return res;
    }
};

int main(int argc, const char **argv)
{
    vector<int> list = {1, 2, 3, 4};
    // printf("%d\n", Solution().xxx());
    // printf("%s\n", Solution().xxx(list).c_str());
    // printVector(Solution().xxx());
    return 0;
}
