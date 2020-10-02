#include "./utils.h"



class Solution {
public:
    /*
    // method-1: 回溯遍历所有解，超时
    int res = INT_MAX;
    void solve(string word1, string word2, int idx1, int idx2, int num) {
        // printf("%d %d %d\n", idx1, idx2, num);
        int len1 = word1.length();
        int len2 = word2.length();
        if (idx1 == len1 && idx2 == len2) {
            // printf("find end, num: %d\n", num);
            res = min(res, num);
        }
        else if (idx1 == len1) {
            solve(word1, word2, idx1, idx2+1, num+1); // 插入
        }
        else if (idx2 == len2) {
            solve(word1, word2, idx1+1, idx2, num+1); // 删除
        }
        else {
            if (word1[idx1] == word2[idx2]) {
                solve(word1, word2, idx1+1, idx2+1, num);
            } else {
                solve(word1, word2, idx1+1, idx2, num+1); // 插入
                solve(word1, word2, idx1, idx2+1, num+1); // 删除
                solve(word1, word2, idx1+1, idx2+1, num+1); // 替换
            }
        }
    }
    int minDistance(string word1, string word2) {
        solve(word1, word2, 0, 0, 0);
        return res;
    }
    */

    vector<vector<int>> dp;
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        
        if (len1 * len2 == 0) return len1 + len2;
        dp = vector<vector<int>>(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 0;i < len1 + 1; i++) {
            dp[i][0] = i;
        }
        for (int i = 0;i < len2 + 1; i++) {
            dp[0][i] = i;
        }
        for (int i = 1;i < len1 + 1; i++) {
            for (int j = 1; j < len2 + 1; j++) {
                int a = dp[i][j - 1] + 1;
                int b = dp[i - 1][j] + 1;
                int c = dp[i - 1][j - 1];
                if (word1[i - 1] != word2[j - 1]) c += 1;
                dp[i][j] = min(a, min(b, c));
            }
        }
        return dp[len1][len2];
    }
};


int main(int argc, const char** argv)
{
    string word1 = "dinitrophenylhydrazine";
    string word2 = "acetylphenylhydrazine";
    printf("%d\n", Solution().minDistance(word1, word2));
    return 0;
}
