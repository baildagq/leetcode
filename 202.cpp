#include "./utils.h"


class Solution {
public:
    // method-1: 判断是否无限循环，这种方法可以通过，
    // 但是实际是错误的，因为搜索次数判定实在太主观了
    // 正确思路是这样：
    // 分为以下3种情况：
    // 1. 正常可以有限步内归结到1
    // 2. 出现循环
    // 3. 无限增长至无穷大
    // 对于第3种情况，可以经过最大的可能的枚举论证发现不存在
    // 对于第2种情况，可以通过set集合判断是否存在重新验证某个数字
    bool isHappy(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        int tryNum = 0;
        while (n != 1) {
            int sum = 0;
            while (n != 0) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            if (sum == 1) {
                return true;
            }
            n = sum;
            tryNum += 1;
            if (tryNum > 10000) {
                return false;
            }
        }
		return false;
    }
};



int main(int argc, const char** argv)
{
    printf("%d\n", Solution().isHappy(19));
    return 0;
}
