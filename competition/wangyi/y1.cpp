#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "utils.h"

using namespace std;

int N;
vector<vector<int>> nums;

void fill(bool posi, int num,  int level) {
    if (level > N / 2) {
        return;
    }
    if (posi) {
        // -> right
        for (int i = level; i <= N - level; i++) {
            nums[level][i] = num ++;
        }
        // -> down
        for (int i = level; i <= N - level; i++) {
            nums[i][N + 1 - level] = num ++;
        }
        // -> left
        for (int i = N + 1 - level; i > level; i--) {
            nums[N + 1 - level][i] = num ++;
        }
        // -> up
        for (int i = N + 1 - level; i > level; i--) {
            nums[i][level] = num ++;
        }
    } else {
        // -> down
        for (int i = level; i <= N - level; i++) {
            nums[i][level] = num ++;
        }
        // -> right
        for (int i = level; i <= N - level; i++) {
            nums[N + 1 - level][i] = num ++;
        }
        // -> up
        for (int i = N + 1 - level; i > level; i--) {
            nums[i][N + 1 - level] = num ++;
        }
        // -> left
        for (int i = N + 1 - level; i > level; i--) {
            nums[level][i] = num ++;
        }
    }
    fill(!posi, num, level + 1);
}

int main(int argc, const char** argv)
{
    int _n;
    scanf("%d", &_n);
    for (int _i = 0; _i < _n; _i ++) { 
        int M;
        scanf("%d %d", &N, &M);
        nums =  vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
        // fill
        fill(true, 1,  1);
        if (N % 2 == 1) {
            nums[N / 2 + 1][N / 2 + 1] = N * N;
        }
        // printVector2D(nums);
        // query
        for (int i = 0;i < M; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", nums[x + 1][y + 1]);
        }
    }
    return 0;
}
