#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Trie {
    public:
        bool isEnd = false;
        Trie* next[26] = {nullptr};
        Trie() {}
        void insert(string s) {
            Trie* curPos = this;
            // reverse insert
            for (int i = s.length() - 1; i >= 0;i --) {
                int numc = s[i] - 'a';
                if (curPos->next[numc] == nullptr) {
                    curPos->next[numc] = new Trie();
                }
                curPos = curPos->next[numc];
            }
            curPos->isEnd = true;
        }
};

class Solution {
    public:
        int respace(vector<string>& dictionary, string sentence) {
            int sentenceSize = sentence.length();
            if (sentenceSize == 0) {
                return 0;
            }


            // build trie tree
            Trie root;
            for (auto& word : dictionary) {
                root.insert(word);
            }

            
            // dp array: 表示以当前下标结尾的字符串中最小未被识别的字符数量
            vector<int> dp(sentenceSize, 0);
            for (int i = 0;i < sentenceSize;i ++) {
                if (i != 0) {
                    // 最坏情况,假设当前字符不能识别
                    dp[i] = dp[i-1] + 1;
                } else {
                    dp[i] = 1;
                }
                Trie* curPos = &root;
                for (int j = i; j >= 0; j --) {
                    // 从当前字符向前进行单词查找
                    // 如果单词 s[j,i] 被找到
                    // 更新 dp[i] = min(dp[i], dp[j-1])
                    // 如果未找到，退出更新
                    int numc = sentence[j] - 'a';
                    if (curPos->next[numc] == nullptr) {
                        break;
                    }
                    if (curPos->next[numc]->isEnd) {
                        if (j-1 >= 0) {
                            dp[i] = min(dp[i], dp[j-1]);
                        } else {
                            dp[i] = 0;
                        }
                    }
                    if (dp[i] == 0) {
                        break;
                    }
                    curPos = curPos->next[numc];
                }
                printf("%d %c %d\n", i, sentence[i], dp[i]);
            }
            printf("\n");
            return dp[sentenceSize-1]; 
        }
};

int main(int argc, const char** argv) {
    vector<string> dictionary = {"mztt","ui","tial"};
    string sentence =""; 
    printf("%d\n", Solution().respace(dictionary, sentence));
    return 0;
}
