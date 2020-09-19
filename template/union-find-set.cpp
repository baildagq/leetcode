#include <cstdio>
#include <vector>

using namespace std;
// vector<int> pa;

int pa[10005];

int find(int x)
{
    if (pa[x] != 0) {
        pa[x] = find(pa[x]);
        return pa[x];
    } else {
        return x;
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    // pa = vector<int>(n+5, 0);

    for (int i = 0; i < m; i++) {
        int flag, x, y;
        scanf("%d %d %d", &flag, &x, &y);
        if (flag == 1) {
            int rootx = find(x);
            int rooty = find(y);
            if (rootx != rooty) {
                pa[rootx] = rooty;
            }
        } else {
            puts(find(x) == find(y) ? "Y" : "N");
        }
    }
    return 0;
}
