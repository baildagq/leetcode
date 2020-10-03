#include "./utils.h"

class Solution {
    bool ok(char c) {
        return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9');
    }
public:
    bool isPalindrome(string s)
    {
        int len = (int)s.length();
        int l = 0, r = len - 1;
        while (l < r) {
            while (l < r && !ok(s[l])) l ++;
            while (r > l && !ok(s[r])) r --;
            int c1 = s[l];
            int c2 = s[r];
            if ('A' <= c1 && c1 <= 'Z') c1 = c1 + 'a' - 'A';
            if ('A' <= c2 && c2 <= 'Z') c2 = c2 + 'a' - 'A';
            if (c1 != c2){
                return false;
            } else {
                l ++;
                r --;
            }
        }
        return true;
    }
};

int main(int argc, const char** argv)
{
    // vector<int> list = {2,3,-2,4};
    string s = "race a car";
    printf("res: %d\n", Solution().isPalindrome(s));
    return 0;
}
