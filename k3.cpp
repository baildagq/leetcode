#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int S, C, num[2], res;
bool stop[2];
vector<int> x;
vector<int> y;
vector<vector<int>> h;

int solve(int i);

void next(int i)
{
    h[x[i]][y[i]] = 1;
    solve((i + 1) % 2);
    h[x[i]][y[i]] = 0;
}

// solve 表示当前玩家能够稳定得到的最大值
int solve(int i)
{
    bool flag = false;
    // up-down direction
    if (y[i] % 2 == 0 && x[i] + 1 < S && h[x[i] + 1][y[i]] == 0) {
        flag = true;
        x[i] = x[i] + 1;
        next(i);
        x[i] = x[i] - 1;
    }
    if (y[i] % 2 == 1 && x[i] - 1 >= 0 && h[x[i] + 1][y[i]] == 0) {
        flag = true;
        x[i] = x[i] - 1;
        next(i);
        x[i] = x[i] + 1;
    }
    // left-right direction
    if (y[i] - 1 >= 0 && h[x[i]][y[i] - 1] == 0) {
        flag = true;
        y[i] = y[i] - 1;
        next(i);
        y[i] = y[i] + 1;
    }
    if (y[i] + 1 < h[x[i]].size() && h[x[i]][y[i] + 1] == 0) {
        flag = true;
        y[i] = y[i] + 1;
        next(i);
        y[i] = y[i] - 1;
    }
    if (flag == false) {
        stop[i] = true;
    }
    if (stop[0] && stop[1]) {
        
    }
    return 0;
}

int main()
{
    int _n;
    scanf("%d", &_n);
    for (int _i = 1; _i <= _n; _i++) {
        num[0] = num[1] = res = 0;
        h.clear();
        x = vector<int>(2, 0);
        y = vector<int>(2, 0);
        scanf("%d %d %d %d %d %d", &S, &x[0], &y[0], &x[1], &y[1], &C);
        x[0] -= 1;
        y[0] -= 1;
        x[1] -= 1;
        y[1] -= 1;
        for (int i = 0; i < S; i++) {
            h.push_back(vector<int>(2 * i + 1, 0));
        }
        // update init place
        h[x[0]][y[0]] = 1;
        h[x[1]][y[1]] = 1;
        for (int i = 0; i < C; i++) {
            // update other finished place
            int R, P;
            scanf("%d %d", &R, &P);
            h[R][P] = 1;
        }
        printf("Case #%d: %d\n", _i, res);
    }
}
