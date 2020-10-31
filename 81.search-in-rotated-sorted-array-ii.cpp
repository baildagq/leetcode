/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 *
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Medium (36.00%)
 * Total Accepted:    43.1K
 * Total Submissions: 119.6K
 * Testcase Example:  '[2,5,6,0,0,1,2]\n0'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 
 * ( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。
 * 
 * 编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。
 * 
 * 示例 1:
 * 
 * 输入: nums = [2,5,6,0,0,1,2], target = 0
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [2,5,6,0,0,1,2], target = 3
 * 输出: false
 * 
 * 进阶:
 * 
 * 
 * 这是 搜索旋转排序数组 的延伸题目，本题中的 nums  可能包含重复元素。
 * 这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？
 * 
 * 
 */



class Solution {
public:
    bool binarySearch(vector<int>& nums, int l, int r, int target) {
        while(l <= r) {
            int mid = (l + r) >> 1;
            if (nums[mid] == target) return true;
            if (nums[mid] < target) l += 1;
            else r -= 1;
        }
        return false;
    }

    int find(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int edge = nums[0];
        while(l < n && nums[l] == edge) l ++;
        if (l == n) return 0;
        while(r >= 0 && nums[r] == edge) r --;
        if (r == -1) return 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= nums[0]) l = mid + 1;
            else r = mid - 1;
        }
        return l - 1;
    }

    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return false;
        int split = find(nums);
        printf("split: %d\n", split);
        return binarySearch(nums, 0, split, target) || binarySearch(nums, split+1, n-1, target);
    }
};
