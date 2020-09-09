#include "./utils.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        // 思路：定位行/列+二分查找
        int lenx = matrix.size();
        if (!lenx)
            return false;
        int leny = matrix[0].size();
        if (!leny)
            return false;

        // part1: line
        for (int i = 0; i < lenx; i++) {
            if (matrix[i][0] <= target && target <= matrix[i][leny - 1]) {
                int left = 0;
                int right = leny - 1;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (matrix[i][mid] == target) {
                        return true;
                    } else if (matrix[i][mid] < target) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
            }
        }

        // part2: row
        for (int i = 0; i < leny; i++) {
            if (matrix[0][i] <= target && target <= matrix[lenx - 1][i]) {
                int left = 0;
                int right = lenx - 1;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (matrix[mid][i] == target) {
                        return true;
                    } else if (matrix[mid][i] < target) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
            }
        }
        return false;
    }
};

int main(int argc, const char** argv)
{
    vector<vector<int>> lists = {
        { 1, 4, 7, 11, 15 },
        { 2, 5, 8, 12, 19 },
        { 3, 6, 9, 16, 22 },
        { 10, 13, 14, 17, 24 },
        { 18, 21, 23, 26, 30 }
    };
    printf("%d\n", Solution().searchMatrix(lists, 0));
    return 0;
}
