#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cmath>

using namespace std;


int main(int argc, const char** argv)
{
    int n, k;
    scanf("%d %d", &n, &k);
    map<float, vector<vector<int>>> info;
    for (int i = 0;i < n; i ++) {
        vector<int> tmp(3, 0);
        scanf("%d %d %d", &tmp[1], &tmp[0], &tmp[2]);
        float ratio = tmp[2] / tmp[1];
        if (info.find(ratio) == info.end()) {
            info[ratio] = {tmp};
        } else {
            info[ratio].push_back(tmp);
        }
    }

    int res = 0;

    for (auto& pair : info) {
        sort(pair.second.begin(), pair.second.end());
    }

    for ()
    printf("%d\n", res);
    return 0;
}
