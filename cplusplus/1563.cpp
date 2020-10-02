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

class Solution
{
public:
    vector<vector<int>> record;
    int solve(vector<int> &stoneValue, int left, int right)
    {
        int res = 0;
        if (left >= right)
        {
            return res;
        }
        if (record[left][right] != -1)
        {
            return record[left][right];
        }
        int areasum = 0;
        for (int i = left; i <= right; i++)
        {
            areasum += stoneValue[i];
        }
        int lsum = 0;
        int rsum = areasum;
        for (int split = left; split < right; split++)
        {
            lsum += stoneValue[split];
            rsum -= stoneValue[split];
            int ans = 0;
            if (lsum < rsum)
            {
                ans = lsum + solve(stoneValue, left, split);
            }
            else if (lsum > rsum)
            {
                ans = rsum + solve(stoneValue, split+1, right);
            }
            else
            {
                ans = max(lsum + solve(stoneValue, left, split), rsum + solve(stoneValue, split+1, right));
            }
            res = max(res, ans);
        }
        record[left][right] = res;
        return res;
    }

    int stoneGameV(vector<int> &stoneValue)
    {
        int size = stoneValue.size();
        record = vector<vector<int>>(size, vector<int>(size, -1));
        if (size == 0 || size == 1)
            return 0;
        int res = solve(stoneValue, 0, size - 1);
        return res;
    }
};

int main(int argc, const char **argv)
{
    vector<int> list = {4};
    printf("%d\n", Solution().stoneGameV(list));
    // printVector(list);
    return 0;
}
