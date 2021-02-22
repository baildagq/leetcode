/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
 *
 * https://leetcode-cn.com/problems/find-duplicate-subtrees/description/
 *
 * algorithms
 * Medium (54.75%)
 * Total Accepted:    18.4K
 * Total Submissions: 33.1K
 * Testcase Example:  '[1,2,3,4,null,2,4,null,null,4]'
 *
 * 给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。
 * 
 * 两棵树重复是指它们具有相同的结构以及相同的结点值。
 * 
 * 示例 1：
 * 
 * ⁠       1
 * ⁠      / \
 * ⁠     2   3
 * ⁠    /   / \
 * ⁠   4   2   4
 * ⁠      /
 * ⁠     4
 * 
 * 
 * 下面是两个重复的子树：
 * 
 * ⁠     2
 * ⁠    /
 * ⁠   4
 * 
 * 
 * 和
 * 
 * ⁠   4
 * 
 * 
 * 因此，你需要以列表的形式返回上述重复子树的根结点。
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    map<string, int> record;
    vector<TreeNode*> res;

    string collect(TreeNode* root)
    {
        if (root == nullptr) {
            return "#";
        }
        string serial = to_string(root->val) + "," + collect(root->left) + "," + collect(root->right);
        if (record.find(serial) == record.end()) {
            record.insert(make_pair(serial, 1));
        } else {
            record[serial] += 1;
            if (record[serial] == 2) {
                res.push_back(root);
            }
        }
        return serial;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
    {
        collect(root);
        return res;
    }
};
