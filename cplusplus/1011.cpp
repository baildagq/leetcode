#include "./utils.h"


class Solution {
    bool ok(const vector<int>& weights, int D, int val) {
        for (auto v : weights) {
            if (v > val) {
                return false;
            }
        }
        int c = 0;
        for (int l = 0, r = 0; l < (int)weights.size(); l = r) {
            int sum = weights[l];
            c += 1;
            for (r = l + 1; r < (int)weights.size(); r ++) {
                if (sum + weights[r] > val) {
                    break;
                }
                sum += weights[r];
            }
        }
        return c <= D;
    }
    
    int binarySearch(const vector<int>& weights, int D, int l, int r){
        int res = 0x3f3f3f3f;
        while ( l <= r ) {
            int mid = (l + r) >> 1;
            if (ok(weights, D, mid)) {
                res = min(res, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int res = binarySearch(weights, D, 0, 0x3f3f3f3f);
        return res;
    }
};



int main(int argc, const char** argv)
{
    vector<int> list = {1,2,3,1,1};
    int D = 4;
    printf("res: %d\n", Solution().shipWithinDays(list, D));
    return 0;
}
