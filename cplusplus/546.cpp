#include <iostream>
#include <cstdlib>
#include <stack>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <climits>
#include "./utils.h"


class Solution {
public:
    int dp[100][100][100];

    int removeBoxes(vector<int>& boxes) {
        memset(dp, 0, sizeof dp);
        return calculatePoints(boxes, 0, boxes.size() - 1, 0);
    }

    int calculatePoints(vector<int>& boxes, int l, int r, int k) {
        printf("%d %d %d\n", l, r, k);
        if (l > r) return 0;
        if (dp[l][r][k] != 0) return dp[l][r][k];
        while (r > l && boxes[r] == boxes[r - 1]) {
            r--;
            k++;
        }
        dp[l][r][k] = calculatePoints(boxes, l, r - 1, 0) + (k + 1) * (k + 1);
        for (int i = l; i < r; i++) {
            if (boxes[i] == boxes[r]) {
                dp[l][r][k] = max(dp[l][r][k], calculatePoints(boxes, l, i, k + 1) + calculatePoints(boxes, i + 1, r - 1, 0));
            }
        }
        // printf("%d %d %d %d\n", l, r, k, dp[l][r][k]);
        printf("   %d\n", dp[l][r][k]);
        return dp[l][r][k];
    }
};


int main(int argc, const char** argv) {
    // vector<int> list = {1,3,2,2,2,3,4,3,1};
    vector<int> list = {1,3,2,2,3};
    // printVector(list);
    printf("%d\n", Solution().removeBoxes(list));
    return 0;
}
