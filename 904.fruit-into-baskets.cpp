/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 *
 * https://leetcode-cn.com/problems/fruit-into-baskets/description/
 *
 * algorithms
 * Medium (42.23%)
 * Total Accepted:    8.5K
 * Total Submissions: 20.3K
 * Testcase Example:  '[1,2,1]'
 *
 * 在一排树中，第 i 棵树产生 tree[i] 型的水果。
 * 你可以从你选择的任何树开始，然后重复执行以下步骤：
 * 
 * 
 * 把这棵树上的水果放进你的篮子里。如果你做不到，就停下来。
 * 移动到当前树右侧的下一棵树。如果右边没有树，就停下来。
 * 
 * 
 * 请注意，在选择一颗树后，你没有任何选择：你必须执行步骤 1，然后执行步骤 2，然后返回步骤 1，然后执行步骤 2，依此类推，直至停止。
 * 
 * 你有两个篮子，每个篮子可以携带任何数量的水果，但你希望每个篮子只携带一种类型的水果。
 * 
 * 用这个程序你能收集的水果树的最大总量是多少？
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[1,2,1]
 * 输出：3
 * 解释：我们可以收集 [1,2,1]。
 * 
 * 
 * 示例 2：
 * 
 * 输入：[0,1,2,2]
 * 输出：3
 * 解释：我们可以收集 [1,2,2]
 * 如果我们从第一棵树开始，我们将只能收集到 [0, 1]。
 * 
 * 
 * 示例 3：
 * 
 * 输入：[1,2,3,2,2]
 * 输出：4
 * 解释：我们可以收集 [2,3,2,2]
 * 如果我们从第一棵树开始，我们将只能收集到 [1, 2]。
 * 
 * 
 * 示例 4：
 * 
 * 输入：[3,3,3,1,2,1,1,2,3,3,4]
 * 输出：5
 * 解释：我们可以收集 [1,2,1,1,2]
 * 如果我们从第一棵树或第八棵树开始，我们将只能收集到 4 棵水果树。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= tree.length <= 40000
 * 0 <= tree[i] < tree.length
 * 
 * 
 */


class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int size = tree.size();
        if (size == 0) return 0;
        vector<int> singleMax(size, 1);
        vector<int> doubleMax(size, 1);

        for (int i = 0; i < size; i++) {
            if (i != 0) {
                if (tree[i - 1] == tree[i]) {
                    singleMax[i] = singleMax[i - 1] + 1;
                    doubleMax[i] = doubleMax[i - 1] + 1;
                } else {
                    singleMax[i] = 1;
                    int j = i - 1;
                    j = j - singleMax[j];
                    if (j < 0 || tree[j] != tree[i]) {
                        doubleMax[i] = singleMax[i] + singleMax[i - 1];
                    } else {
                        doubleMax[i] = singleMax[i] + doubleMax[i - 1];
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i < size; i++) {
            res = max(res, singleMax[i]);
            res = max(res, doubleMax[i]);
        }
        return res;
    }
};



