#include <iostream>
#include <cstdlib>
#include <stack>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 == 0 || n2 == 0) {
            return {};
        }
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        int i = 0, j = 0;
        while(i != nums1.size() && j != nums2.size()) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                i += 1;
                j += 1;
            } else if (nums1[i] < nums2[j]) {
                i += 1;
            } else {
                j += 1;
            }
        }
        return res;
    }
};

int main(int argc, const char** argv) {
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {};
    vector<int> res = Solution().intersect(nums1, nums2);
    for(auto& v:res) {
        printf("%d ", v);
    }
    printf("\n");
    return 0;
}
