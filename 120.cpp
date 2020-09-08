#include <iostream>
#include <cstdlib>
#include <stack>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int len = triangle.size();
        if (len == 0) {
            return 0;
        }

        for (int i = 1;i < len;i ++) {
            triangle[i][0] += triangle[i-1][0];
            for (int j = 1; j < triangle[i].size() - 1; j ++) {
                triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
            }
            triangle[i].back() += triangle[i-1].back();
        }

        int res = triangle.back()[0];
        for (auto& v:triangle.back()) {
            res = (v<res) ? v : res;
        }
        return res;
    }
};

int main(int argc, const char** argv) {
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    printf("%d\n", Solution().minimumTotal(triangle));
    return 0;
}
