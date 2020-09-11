#include "./utils.h"

class Solution {
public:
    int trap(vector<int>& height)
    {
        int res = 0;
        int size = height.size();
        if (size == 0)
            return res;
        vector<pair<int, int>> left;
        vector<pair<int, int>> right;

        // 找到从左边看到的最高峰
        left.push_back(make_pair(0, height[0]));
        for (int i = 1; i < size; i++) {
            if (height[i] > left.back().second) {
                left.push_back(make_pair(i, height[i]));
            }
        }

        // 找到从右边看到的最高峰
        right.push_back(make_pair(size - 1, height[size - 1]));
        for (int i = size - 1; i >= left.back().first; i--) {
            if (height[i] > right.back().second) {
                right.push_back(make_pair(i, height[i]));
            }
        }

        // 求和：左边最高峰左边 + 右边最高峰右边 + 左右最高峰中间
        int maxheight = 0;
        for (int i = 0; i < left.size() - 1; i++) {
            maxheight = left[i].second;
            for (int j = left[i].first + 1; j < left[i+1].first; j ++) {
                res += max(maxheight - height[j], 0);
            }
        }
        for (int i = 0; i < right.size() - 1; i++) {
            maxheight = right[i].second;
            for (int j = right[i].first - 1; j > right[i+1].first; j --) {
                res += max(maxheight - height[j], 0);
            }
        }
        maxheight = left.back().second;
        for (int i = left.back().first + 1; i < right.back().first; i++) {
            res += max(maxheight - height[i], 0);
        }
        return res;
    }
};

int main(int argc, const char** argv)
{
    vector<int> list = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    printf("%d\n", Solution().trap(list));
    return 0;
}
