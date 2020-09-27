#include "./utils.h"


class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return false;
        // time: O(n) space: O(n)
        vector<int> visited(size, -1);
        int level = 0; // 用于判断不同的层
        // 每个元素最多遍历2遍
        for (int i = 0; i < size; i++) {
            printf("i: %d\n", i);
            if (visited[i] != -1) {
                continue;
            }
            if (nums[i] % size == 0) {
                visited[i] = level;
                level ++;
                continue;
            }
            // 以新的未遍历过并且不会构成长度为1的循环的节点，作为起始节点
            bool isForward = nums[i] > 0;
            visited[i] = level;
            int idx = (i +  nums[i] + size) % size;
            while (idx < 0)  {
                idx += size;
            }
            while (true) {
                printf("idx: %d", idx);
                if ((nums[idx] > 0) == isForward) {
                    if (visited[idx] != -1) {
                        if (visited[idx] == level) {
                            return true;
                        } else {
                            break;
                        }
                    } else {
                        visited[idx] = level;
                        if (nums[idx] % size == 0) {
                            // 循环长度不能为1
                            break;
                        }
                        idx = (idx + nums[idx] + size) % size;
                        while (idx < 0)  {
                            idx += size;
                        }
                    }
                } else {
                    break;
                }
                // printVector(visited);
            }
            level ++;
            // printVector(visited);
        }
        return false;
    }
};



int main(int argc, const char** argv)
{
    vector<int> list = {-2,-17,-1,-2,-2};
    printf("res: %d\n", Solution().circularArrayLoop(list));
    return 0;
}
