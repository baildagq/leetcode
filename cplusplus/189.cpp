#include "./utils.h"



class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k %= size;
        for (int i = 0, count = 0; count < size; i++) {
            int curr = i;
            int prev = nums[i];
            int next = (curr + k) % size;
            do {
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                curr = next;
                next = (curr + k) % size;
                count ++;
            } while(curr != i);
        }
    }
};


int main(int argc, const char** argv)
{
    // vector<int> list = {2,3,-2,4};
    // printf("res: %d\n", Solution().xxx(list));
    return 0;
}
