#include "./utils.h"


class Solution {
public:
    int superEggDrop(int K, int N) {
        int l = 1, r = N, mid = 0;
        int res = 0;
        while (K != 1 && l < r) {
            mid = l + (r - l) / 2;
            printf("K:%d l:%d r:%d mid:%d\n", K, l, r, mid);
            l = mid + 1;
            res += 1;
            K -= 1;
        }
        if (l != 1) {
            // 左边找到了边界
            // 当 i 未碎,只剩 j, k, l未知时，可以通过一次
        }
        res += (r != l) ? (r - l + 1) : 0;
        return res;
    }
};



int main(int argc, const char** argv)
{
    int K = 2, N = 6;
    printf("res: %d\n", Solution().superEggDrop(K, N));
    return 0;
}
