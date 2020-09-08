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
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int listNum = nums.size();
        if (listNum == 0) {
            return {0, 0};
        }

        vector<pair<int, int>> all;
        for (int i = 0;i < listNum;i ++) {
            for (auto& num : nums[i]) {
                all.push_back(make_pair(num, i));
            }
        }
        sort(all.begin(), all.end());

        int l, r, resl, resr, minLen;
        l = r = 0;
        resl = all.front().first;
        resr = all.back().first;
        minLen = all.back().first - all.front().first;
        vector<int> appearNum(listNum, 0);
        int appearKind = 0;
        

        // find res
        while (r != all.size()) {
            int listIndex = all[r].second;
            if (appearNum[listIndex] == 0) {
                appearKind += 1;
            } 
            appearNum[listIndex] += 1;
            // 去除新添加的队列，在队首的部分
            while (l != r && appearNum[all[l].second] > 1) {
                appearNum[all[l].second] -= 1;
                l += 1;
            }

            // printf("current l:%d r:%d appearKind:%d\n", l, r, appearKind);
            // for (int i = l; i <= r;i ++) {
            //     printf("%d %d\n", all[i].first, all[i].second);
            // }


            if (appearKind == listNum) {
                int intervalLen = all[r].first - all[l].first;
                if (intervalLen < minLen) {
                    minLen = intervalLen;
                    resl = all[l].first;
                    resr = all[r].first;
                } 
            }
            r += 1;
        }
        return {resl, resr};
    }
};


int main(int argc, const char** argv) {
	// vector<vector<int>> nums = {{4,10,15,24,26}, {0,9,12,20}, {5,18,22,30}};
	vector<vector<int>> nums = {{0}, {8000}, {10}};
	vector<int> res = Solution().smallestRange(nums);
    printf("res\n");
	printVector(res);
    return 0;
}
