#include <iostream>
#include <cstdlib>
#include <stack>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <climits>
#include <unordered_set>
#include "./utils.h"

class Solution
{
public:
    vector<vector<int>> res;
    vector<int> nums;
    vector<int> item;
    unordered_set<int> hashset;
    int size;

    int getHash()
    {
        int base = 263;
        int mod = int((1E9) + 7);
        int hashValue = 0;
        for (const auto &x : item)
        {
            hashValue = 1LL * hashValue * base % mod + (x + 101);
            hashValue %= mod;
        }
        return hashValue;
    }

    void dfs(int index)
    {
        if (index == size)
            return;
        if (index == 0 || item.size() == 0 || item.back() <= this->nums[index])
        {
            item.push_back(nums[index]);
            int hashValue = getHash();
            if (hashset.find(hashValue) == hashset.end())
            {
                if (item.size() > 1)
                {
                    this->res.push_back(item);
                    hashset.insert(hashValue);
                }
                dfs(index + 1);
            }
            item.pop_back();
        }
        dfs(index + 1);
    }

    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        size = nums.size();
        if (size == 0 || size == 1)
            return this->res;
        this->nums = nums;
        dfs(0);
        return this->res;
    }
};

int main(int argc, const char **argv)
{
    vector<int> list = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    vector<vector<int>> res = Solution().findSubsequences(list);
    return 0;
}
