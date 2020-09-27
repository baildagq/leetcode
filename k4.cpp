#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int _n;
    scanf("%d", &_n);
    for (int _i = 1; _i <= _n; _i ++) {
        int res = 0;
        int S, ra, pa, rb, pb, c;;
        scanf("%d %d %d %d %d %d", &S, &ra, &pa, &rb, &pb, &c);
        vector<vector<int>> house = {{0}, {0, 0, 0}};
        ra -= 1;
        pa -= 1;
        rb -= 1;
        pb -= 1;
        house[ra][pa] = 1;
        house[rb][pb] = 1;
        for (int i = 0;i < c; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            house[x - 1][y - 1] = 1;
        }
        // 0 0
        if (ra == 0 && pa == 0) {
            if (house[1][1] == 1) {
                res = 0;
            } else {
                res = 1;
                if (house[1][0] == 0 || house[1][2] == 0) {
                    res = 2;
                }
            }
        }
        // 1 0
        if (ra == 1 && pa == 0) {
            if (house[1][1] == 1) {
                res = 0;
            } else {
                res = 1;
                if (house[0][0] == 0 || house[1][2] == 0) {
                    res = 2;
                }
            }
        }
        // 1 2
        if (ra == 1 && pa == 2) {
            if (house[1][1] == 1) {
                res = 0;
            } else {
                res = 1;
                if (house[0][0] == 0 || house[1][0] == 0) {
                    res = 2;
                }
            }
        }
        // 1 1
        if (ra == 1 && pa == 1) {
            if (house[0][0] == 0) {
                res += 1;
            }
            if (house[1][0] == 0) {
                res += 1;
            }
            if (house[1][2] == 0) {
                res += 1;
            }
        }
        printf("Case #%d: %d\n", _i, res);
    }
}
