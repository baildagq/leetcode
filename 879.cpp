#include "./utils.h"


class Solution {
public:
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        int res = 0;
        int size = group.size();
        vector<pair<int, int>> info;
        for (int i = 0; i < size; i++) {
            if (group[i] < G || (group[i] == G && profit[i] >= P)){
                info.push_back(make_pair(profit[i], group[i]));
            }
        }
        sort(info.begin(), info.end());
        reverse(info.begin(), info.end());

        size = info.size();
        for (int i = 0; i < size; i++) {
            
        }
        return res;
    }
};



int main(int argc, const char** argv)
{
    int G = 5;
    int P = 3;
    vector<int> group{2, 2};
    vector<int> profit{2, 3};
    printf("res: %d\n", Solution().profitableSchemes(G, P, group, profit));
    return 0;
}
