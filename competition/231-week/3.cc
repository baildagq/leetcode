#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};

class Solution {
public:
    vector<vector<pair<int, int>>> link;
    vector<int> flag;
    vector<int> mindis;
    int res = 0;
    int n = 0;

    void dfs(int idx, int sum)
    {
        if (sum < mindis[idx]) {
            mindis[idx] = sum;
        }
        for (auto p : link[idx]) {
            auto next = p.first;
            auto val = p.second;
            if (flag[next] == 0) {
                flag[idx] = 1;
                dfs(next, sum + val);
                flag[idx] = 0;
            }
        }
    }

    void solve(int idx)
    {
        if (idx == n) {
            this->res += 1;
        }
        for (auto p : link[idx]) {
            auto next = p.first;
            auto val = p.second;
            if (flag[next] == 0 && mindis[idx] > mindis[next]) {
                flag[idx] = 1;
                solve(next);
                flag[idx] = 0;
            }
        }
    }

    int countRestrictedPaths(int n, vector<vector<int>>& edges)
    {
        this->n = n;
        link = vector<vector<pair<int, int>>>(n + 1);
        flag = vector<int>(n + 1, 0);
        mindis = vector<int>(n + 1, INT_MAX);

        for (auto edge : edges) {
            auto x = edge[0];
            auto y = edge[1];
            auto val = edge[2];
            link[x].push_back(make_pair(y, val));
            link[y].push_back(make_pair(x, val));
        }

        // dfs
        flag[n] = 1;
        dfs(n, 0);
        flag[n] = 0;

        for (int i = 1; i <= n; i++) {
            printf("i %d mindis %d\n", i, mindis[i]);
        }

        // solve res
        solve(1);
        return this->res;
    }
};

int main()
{
    // int n = 7;
    // vector<vector<int>> edges = { { 1, 3, 1 }, { 4, 1, 2 }, { 7, 3, 4 }, { 2, 5, 3 }, { 5, 6, 1 }, { 6, 7, 2 }, { 7, 5, 3 }, { 2, 6, 4 } };
    int n = 5;
    vector<vector<int>> edges = { { 1, 2, 3 }, { 1, 3, 3 }, { 2, 3, 1 }, { 1, 4, 2 }, { 5, 2, 2 }, { 3, 5, 1 }, { 5, 4, 10 } };
    printf("%d\n", Solution().countRestrictedPaths(n, edges));
    return 0;
}
