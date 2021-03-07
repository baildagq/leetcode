#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};

class Solution {
public:
    using LL = long long;
    int minElements(vector<int>& nums, int limit, int goal)
    {
        LL sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        LL diff = abs(goal - sum);
        int res = (diff / limit * limit == diff) ? diff / limit : diff / limit + 1;
        return res;
    }
};

int main()
{
    vector<int> nums { 1, -10, 9, 1 };
    int limit = 100;
    int goal = 0;
    printf("%d\n", Solution().minElements(nums, limit, goal));
    return 0;
}
