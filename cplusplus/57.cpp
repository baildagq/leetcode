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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        return res;    
    }
};



int main(int argc, const char** argv) {
    vector<vector<int>> intervals = {{}};
    vector<int> newInterval = {1,2,3,4};

    vector<vector<int>> res = Solution().insert(intervals, newInterval);
    printVector2D(res);
    return 0;
}
