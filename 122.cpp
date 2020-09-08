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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        int curmax = prices[0];
        int curmin = prices[0];
        int res = 0;
        bool hold = false;

        int begin = 0, end = n-1;
        while (begin+1 < n && prices[begin+1] <= prices[begin]) {++begin;}
        while (end-1 >= 0 && prices[end-1] >= prices[end]) {--end;}
        printf("begin: %d end: %d %d\n", begin, end, prices[end]);
        for (int i = begin;i <= end;i ++) {
            if (hold == false) {
                if (prices[i] < prices[i+1]) {
                    hold = true;
                    res -= prices[i];
                    printf("buy %d %d\n", i, prices[i]);
                }
            } else {
                if (i == end || prices[i] > prices[i+1]) {
                    hold = false;
                    res += prices[i];
                    printf("sold %d %d\n", i, prices[i]);
                }
            }
        }
        return res;
    }
};

int main(int argc, const char** argv) {
    vector<int> list = {1,9,6,9,1,7,1,1,5,9,9,9};
    cout << Solution().maxProfit(list) << endl;
    return 0;
}
