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
#include <iterator>
#include <sstream>


class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n+1, 1);
        vector<int> waitList(n, 0);
        for (int i = 1;i < n+1;i ++) {
            factorial[i] = factorial[i-1] * i;
        }
        for (int i = 0;i < n+1;i ++) {
            waitList[i] = i+1;
        }

        vector<int> res;
        while (k != 0 && n != 0) {
            int idx = ((k%factorial[n-1]) == 0) ? k / factorial[n-1] - 1 : k / factorial[n-1];
            k -= (idx * factorial[n-1]);
            res.push_back(waitList[idx]);
            waitList.erase(waitList.begin() + idx);
            n -= 1;
        }
        std::stringstream ss;
        string testString;
        std::copy(res.begin(),res.end(),ostream_iterator<int>(ss,""));
        testString = ss.str();
        return testString;
    }
};


int main(int argc, const char** argv) {
    string res = Solution().getPermutation(4, 9);
    printf("%s\n", res.c_str());
    return 0;
}
