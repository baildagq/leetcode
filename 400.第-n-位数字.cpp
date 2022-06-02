#include <vector>
#include <iostream>
/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第 N 位数字
 */

// @lc code=start
class Solution {
public:
    int findNthDigit(int n) {
        long long accu_bit_count = 1;
        long long each_bit_count = 1;
        long long base = 1;
        while(accu_bit_count + base * 9 * each_bit_count <= n) {
            accu_bit_count += base * 9 * each_bit_count;
            each_bit_count += 1;
            base *= 10;
        }
        long long left_bit_num = n - accu_bit_count;
        long long number_index = left_bit_num / each_bit_count;
        long long number = base + number_index;
        left_bit_num = n - accu_bit_count - number_index * each_bit_count;
        // remove high bit by module
        for (auto i = 0; i < left_bit_num; i++)
        {
            number = number % base;
            base /= 10;
        }
        // get current bit by divide
        int bit = number / base;
        return bit;
    }
};
// @lc code=end


int main() 
{
    Solution solution;
    int bit = solution.findNthDigit(3);
    std::cout << bit << std::endl;
    return 0;
}