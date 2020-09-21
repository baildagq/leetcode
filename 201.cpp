#include "./utils.h"

class Solution {
public:
    int rangeBitwiseAnd(int m, int n)
    {
        bitset<32> n1(m);
        bitset<32> n2(n);
        bitset<32> res;

        for (int i = 31; i >= 0; i--) {
            if (n1[i] == n2[i]) {
                // printf("%d ", i);
                res[i] = n1[i];
            } else {
                break;
            }
        }
        return int(res.to_ulong());
    }
};

int main(int argc, const char** argv)
{
    int m = 0, n = 2147483647;
    printf("res: %d\n", Solution().rangeBitwiseAnd(m, n));
    return 0;
}
