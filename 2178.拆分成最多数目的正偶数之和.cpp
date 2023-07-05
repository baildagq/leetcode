#include "common.h"
/*
 * @lc app=leetcode.cn id=2178 lang=cpp
 *
 * [2178] 拆分成最多数目的正偶数之和
 */

// @lc code=start
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> res;
        if (finalSum % 2 != 0) {
            return {};
        }
        long long twoNum = finalSum / 2;
        long long lastNumContainTwoConunt = 0;
        while(twoNum != 0) {
            long long tryCount = lastNumContainTwoConunt + 1;
            if (twoNum <= 2 * tryCount) {
                res.push_back(twoNum * 2);
                twoNum -= twoNum;
            } else {
                res.push_back(tryCount * 2);
                lastNumContainTwoConunt = tryCount;
                twoNum -= tryCount;
            }
        }
        return res;
    }
};

// @lc code=end

int main() {
    long long finalSum = 28;
    Solution solu;
    std::vector<long long> res = solu.maximumEvenSplit(finalSum);
    printVector(res);
    return 0;
}