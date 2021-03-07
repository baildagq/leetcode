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
    bool checkOnesSegment(string s)
    {
        bool res = false;
        int i = 0;
        int curOneLen = 0;
        while (i < s.size()) {
            if (s[i] == '0') {
                if (curOneLen != 0) {
                    if (res == false) {
                        res = true;
                        curOneLen = 0;
                    } else {
                        return false;
                    }
                }
                while (i < s.size() && s[i] == '0') {
                    i++;
                }
            }
            if (s[i] == '1') {
                while (i < s.size() && s[i] == '1') {
                    curOneLen++;
                    i++;
                }
            }
        }
        if (curOneLen != 0) {
            if (res == false) {
                res = true;
                curOneLen = 0;
            } else {
                return false;
            }
        }
        return res;
    }
};

int main()
{
    printf("%d\n", Solution().checkOnesSegment("0110"));
    return 0;
}
