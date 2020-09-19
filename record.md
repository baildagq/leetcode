### 2020.09.18

**树状数组**

https://wangdh15.github.io/2020/03/24/%E6%A0%91%E7%8A%B6%E6%95%B0%E7%BB%84/



**并查集**

<img src=".\record.assets\image-20200918154235266.png" alt="image-20200918154235266" style="zoom: 67%;" />

```c++
#include <cstdio>
#include <vector>

using namespace std;
vector<int> pa;

int find(int x) {
    if (pa[x] != 0) {
        pa[x] = find(pa[x]);
        return pa[x];
    } else {
        return x;
    }
}
    
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    pa = vector<int>(n+5, 0);
    
    for (int i = 0; i < m; i++) {
        int flag, x, y;
        scanf("%d %d %d", &flag, &x, &y);
        if (flag == 1) {
            pa[find(x)] = find(y);
        } else {
            puts(find(x) == find(y) ? "Y" : "N");
        }
    }
    return 0;
}
```



并查集分析：



### 2020.09.19

**gdb** 

https://www.cs.cmu.edu/~gilpin/tutorial/