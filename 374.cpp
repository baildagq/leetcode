#include "./utils.h"

class Solution {
public:
    int guess(int n) {
        if (n == 6) return 0;
        if (n > 6) return 1;
        if (n < 6) return -1;
        return 0;
    }

    int guessNumber(int n)
    {
        int l = 1, r = n;
        int mid = l + (r - l) / 2;
        int predict = guess(mid);

        while (predict != 0) {
            if (predict == 1) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
            mid = l + (r - l) / 2;
            predict = guess(mid);
        }
        return mid;
    }
};

int main(int argc, const char** argv)
{
    printf("%d\n", Solution().guessNumber(10));
    return 0;
}
