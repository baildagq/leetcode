#include "./utils.h"

#include <cstdio>
#include <algorithm>

// 全局变量会将值默认置为0
int dp[1005][105];
int t[105]; // 装入第i种物品需要花费的代价
int v[105]; // 装入第i种物品能带来的价值

// version-3:  // dp[i][j] 表示使用前i种物品，使得体积不超过j时，能够得到的最大利润
// 观察可以发现更新dp[i][j]时，只与dp[i-1]相关，所以改变j的遍历顺序不会影响正确性
int main() {
	int m, n; // m: 体积  n: 种类数
	scanf("%d %d", &m, &n);
	for (int i = 1;i <= n; i++) {
		scanf("%d %d", &t[i], &v[i]);
	}
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
			// 不选新添加的物品
            dp[i][j] = dp[i-1][j];
            if (j >= t[i]) {
				// 容量大于新添加的物品，尝试加入新物品
                dp[i][j] = std::max(dp[i][j], dp[i-1][j-t[i]] + v[i]);
            }
        }
    }
	int res = dp[n][m];
    printf("res: %d\n", res);
	return 0;
}


/*
// version-2:  // dp[i][j] 表示使用前i种物品，使得体积不超过j时，能够得到的最大利润
int main() {
	int m, n; // m: 体积  n: 种类数
	scanf("%d %d", &m, &n);
	for (int i = 1;i <= n; i++) {
		scanf("%d %d", &t[i], &v[i]);
	}
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
			// 不选新添加的物品
            dp[i][j] = dp[i-1][j];
            if (j >= t[i]) {
				// 容量大于新添加的物品，尝试加入新物品
                dp[i][j] = std::max(dp[i][j], dp[i-1][j-t[i]] + v[i]);
            }
        }
    }
	int res = dp[n][m];
    printf("res: %d\n", res);
	return 0;
}
*/

/*
// version-1:  // dp[i][j] 表示使用前i种物品，使得体积恰好为j时，能够得到的最大利润
int main() {
	int m, n; // m: 体积  n: 种类数
	scanf("%d %d", &m, &n);
	for (int i = 1;i <= n; i++) {
		scanf("%d %d", &t[i], &v[i]);
	}
	dp[0][0] = 0;
	for (int i = 1;i <= m; i++) {
		dp[0][i] = INT_MIN;
	}
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
			// 不选新添加的物品
            dp[i][j] = dp[i-1][j];

            if (j >= t[i]) {
				// 容量大于新添加的物品，尝试加入新物品
                dp[i][j] = std::max(dp[i][j], dp[i-1][j-t[i]] + v[i]);
            }

        }
    }
	int res = 0;
	for (int i = 1; i <= m; i++) {
		res = std::max(res, dp[n][i]);
	}
    printf("res: %d\n", res);
	return 0;
}
*/
