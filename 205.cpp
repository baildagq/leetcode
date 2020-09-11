#include "./utils.h"


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> maptable;
        unordered_set<char> settable;
        int len = s.size();
        for (int i = 0;i < len; i++) {
            if (maptable.find(s[i]) != maptable.end()) {
                if (maptable.find(s[i])->second != t[i]) {
                    return false;
                }
            } else {
                if (settable.find(t[i]) != settable.end()) {
                    return false;
                }
                maptable.try_emplace(s[i], t[i]);
                settable.insert(t[i]);
            }
        }
        return true;
    }
};



int main(int argc, const char** argv)
{
    string s1 = "ab";
    string s2 = "aa";
    printf("%d\n", Solution().isIsomorphic(s1, s2));
    return 0;
}
