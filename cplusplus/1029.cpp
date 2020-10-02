#include "./utils.h"


class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int size = costs.size();
        vector<int> diff(size, 0);
        int res = 0;
        for (int i = 0;i < size; i++) {
            res += costs[i][0];
            diff[i] = costs[i][0] - costs[i][1];
        }
        sort(diff.begin(), diff.end());
        for (int i = size / 2; i < size; i++) {
            res -= diff[i];
        }
        return res;
    }
};



int main(int argc, const char** argv)
{
    vector<vector<int>> list = {{10,20},{30,200},{400,50},{30,20}};
    printf("res: %d\n", Solution().twoCitySchedCost(list));
    return 0;
}
