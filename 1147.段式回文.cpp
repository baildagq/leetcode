/*
 * @lc app=leetcode.cn id=1147 lang=cpp
 *
 * [1147] 段式回文
 */

// @lc code=start

// #include <string>
// #include <iostream>
// using namespace std;

class Solution {
public:
    int longestDecomposition(string text) {
        // int l = text.length() / 2 - (1 - text.length() % 2);
        // int r = text.length() / 2;
        int res = 0;
        string lsubstr = "";
        string rsubstr = "";
        int l = 0;
        int r = text.length() - 1;
        while (l <= r) {
            lsubstr = lsubstr + text[l];
            rsubstr = text[r] + rsubstr;
            if (lsubstr == rsubstr) {
                res += (l == r) ? 1 : 2;
                lsubstr = "";
                rsubstr = "";
            }
            l += 1;
            r -= 1;
        }
        if (lsubstr != "") {
            res += 1;
        }
        return res == 0 ? 1 : res;
    }
};


// int main() {
//     Solution solu = Solution();
//     string text = "ghiabcdefhelloadamhelloabcdefghi";
//     std::cout << solu.longestDecomposition(text) << std::endl;
// }


// @lc code=end

