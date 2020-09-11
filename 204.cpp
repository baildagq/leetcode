#include "./utils.h"

class Solution {
public:
    bool isPrime(int n) {
        if (n == 2) return true;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false; 
        }
        return true;
    }

    int countPrimes(int n) {
        int res = 0;
        for (int i = 2; i < n; i ++) {
            if (isPrime(i)) {
                printf("%d ", i);
                res += 1;
            }
        }
        printf("\n");
        return res;
    }
};


int main(int argc, const char** argv)
{
    printf("%d\n", Solution().countPrimes(9));
    return 0;
}
