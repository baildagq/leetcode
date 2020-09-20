#include "./utils.h"

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        bool newRange = true;
        int head, tail;
        vector<string> res;
        int size = nums.size();
        // 检测一段是否结束的方法是，查看下一个元素是否等于当前结尾元素+1
        for (int i = 0; i < size; i++) {
            if (newRange) {
                head = nums[i];
            }
            tail = nums[i];
            if (i + 1 == size || tail + 1 != nums[i + 1]) {
                if (head == tail) {
                    res.push_back(to_string(head));
                } else {
                    res.push_back(to_string(head) + "->" + to_string(tail));
                }
                newRange = true;
            } else {
                newRange = false;
            }
            printf("newrange: %d head: %d tail: %d\n", newRange, head, tail);
        }
        return res;
    }
};

int main(int argc, const char** argv)
{
    vector<int> list = {0, 1, 2, 4, 5, 7};
    vector<string> res = Solution().summaryRanges(list);
    printVector(res);
    return 0;
}
