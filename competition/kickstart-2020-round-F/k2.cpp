#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int _n;
    scanf("%d", &_n);
    for (int _i = 1; _i <= _n; _i ++) {
        int N, K;
        int res = 0;
        scanf("%d %d", &N, &K);
        int last = 0;
        vector<pair<int, int>> info;
        for (int i = 0; i < N; i++) {
            int start, end;
            scanf("%d %d", &start, &end);
            info.push_back(make_pair(start, end));
        }
        sort(info.begin(), info.end());
        for (int i = 0;i < N; i++) {
            int start = info[i].first;
            int end = info[i].second;
            // printf("start: %d end: %d\n", start, end);
            if (last >= end) {
                continue;
            }
            if (last < start) {
                last = start;
            }
            int num = ((end - last) % K == 0) ? (end - last) / K : (end - last) / K + 1;
            res += num;
            last += num * K;
        }
        printf("Case #%d: %d\n", _i, res);
    }
}
