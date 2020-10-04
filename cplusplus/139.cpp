#include "./utils.h"

// method-1: backtrace? tle
/*
class Solution {
public:
    bool solve(string s, int idx, vector<string>& wordDict)
    {
        if (idx == (int)s.length())
            return true;
        for (auto word : wordDict) {
            int len = word.length();
            if (idx + len <= (int)s.length() && s.compare(idx, len, word) == 0) {
                if (solve(s, idx + len, wordDict)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict)
    {
        return solve(s, 0, wordDict);
    }
};
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        auto dict = unordered_set<string>();
        for (auto w : wordDict) {
            dict.insert(w);
        }
        vector<bool> dp(s.size() + 1, 0);
        dp[0] = true;
        for (int i = 1; i < (int)s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.find(s.substr(j, i-j)) != dict.end()) {
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }
};

int main(int argc, const char** argv)
{
    string s = "catsandog";
    vector<string> wordDict{"cats", "dog", "sand", "and", "cat"};
    printf("\nres: %d\n", Solution().wordBreak(s, wordDict));
    return 0;
}
