#include "./utils.h"





int main(int argc, const char** argv)
{
    vector<int> list = { 1, 2, 3, 4, 5 };
    vector<vector<int>> lists = { { -240, -657 }, { -27, -188 }, { -616, -247 } };
    printf("%d\n", Solution().maxPoints(lists));
    return 0;
}
