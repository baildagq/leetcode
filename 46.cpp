#include <iostream>
#include <cstdlib>
#include <stack>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void solve(vector<int>& nums, vector<int>& flag, vector<vector<int>>& res, vector<int>& item, int depth){
        for(int i = 0;i < nums.size();i ++) {
            if (flag[i] == 0) {
                flag[i] = 1;
                item.push_back(nums[i]);
                if (depth == nums.size() - 1) {
                    res.push_back(item);
                } else {
                    solve(nums, flag, res, item, depth+1);
                }
                flag[i] = 0;
                item.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        if (n == 0) {
            res.push_back(vector<int>());
            return res;
        }
        vector<int> item;
        vector<int> flag(n, 0);
        solve(nums, flag, res, item, 0);
        return res;
    }
};

int main(int argc, const char** argv) {
	vector<int> nums = {};
	vector<vector<int>> res = Solution().permute(nums);
    printf("result\n");
    for (auto& item : res) {
        for (auto& val : item) {
            printf("%d ", val);
        }
        printf("\n");
    }
    return 0;
}
