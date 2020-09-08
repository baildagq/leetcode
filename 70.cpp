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


class Solution {
public:  
    vector<int> methods;
    
    int solve(int n) {
        if (methods[n] == -1) {
            methods[n] = solve(n-2) + solve(n-1);
        }
        return methods[n];
    }

    int climbStairs(int n) {
        int res = 0;
        methods = vector<int>(n+1, -1);
        methods[1] = 1;
        methods[2] = 2;
        return solve(n);
    }
};


int main(int argc, const char** argv) {
    printf("%d\n", Solution().climbStairs(40));
    return 0;
}
