#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1;i <= n;i ++) {
        int num, limit;
        scanf("%d %d", &num, &limit);
        vector<vector<int>> level(num);
        for (int j = 0;j < num; j++) {
            int money = 0;
            scanf("%d", &money);
            int l = (money % limit == 0) ? (money / limit) : (money / limit + 1);
            level[j] = {l, j+1};
        }

        sort(level.begin(), level.end());
        printf("Case #%d: ", i);
        for (auto v : level) {
            printf("%d ", v[1]);
        }
        printf("\n");
    }
}
