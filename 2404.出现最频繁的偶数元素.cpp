/*
 * @lc app=leetcode.cn id=2404 lang=cpp
 *
 * [2404] 出现最频繁的偶数元素
 */

// #include <map>
// #include <vector>
// #include <unordered_map>
// #include <iostream>
// using namespace std;

// @lc code=start
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int res = -1;
        int res_count = 0;
        std::map<int, int> m;
        for (auto v : nums) {
        // for (auto i = 0; i < nums.size(); i ++) {
        //     int v = nums[i];
            if (m.find(v) != m.end()) {
                m[v] += 1;
            } else {
                m.insert(std::make_pair(v, 1));
            }
        }

        for (auto iter = m.begin(); iter != m.end(); iter ++) {
            if (iter->first % 2 == 0 and iter->second > res_count) {
                res = iter->first;
                res_count = iter->second;
            } 
        }
        return res;
    }
};

// int main() {
//     Solution solu;
//     std::vector<int> nums = {1, 2, 2, 2, 3, 4, 6, 6, 6};
//     std::cout << solu.mostFrequentEven(nums) << std::endl;
// }
// @lc code=end

