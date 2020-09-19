#include "./utils.h"

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       vector<vector<int>> res; 
        int size = nums.size();

       return res;
    }
};

int main(int argc, const char** argv)
{
    vector<int> list = {1, 1, 2};
    vector<vector<int>> res = Solution().permuteUnique(list);
    printVector2D(res);
    return 0;
}