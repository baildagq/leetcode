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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> copynums1;
        copynums1.assign(nums1.begin(), nums1.end()+m);
        nums1.clear();
        auto i = copynums1.begin();
        auto j = nums2.begin();
        while (i != copynums1.end() || j != nums2.end()) {
            if (i == copynums1.end()) {
                nums1.push_back(*j);
                j ++;
            } else if (j == nums2.end()) {
                nums1.push_back(*i);
                i ++;
            } else {
                if (*i < *j) {
                    nums1.push_back(*i);
                    i ++;
                } else {
                    nums1.push_back(*j);
                    j ++;
                }
            }
        }
    }
};


int main(int argc, const char** argv) {
    vector<int> nums1{1,2,3,4,10,11};
    vector<int> nums2{4,5,6,7,2,3,4};
    Solution().merge(nums1, nums1.size(), nums2, nums2.size());
    printVector(nums1);
    return 0;
}
