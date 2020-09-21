### 2020.09.21

**47** 全排列

重新做了47题，已经完全不会做了，这遍又是看了题解才能解出
复杂度实现为O(n*n!)
能够想出通过回溯的方法得到全排列，但是因为有了重复数字，如何进行判重是一个很难搞的事
```
if (vis[i] || (i > 0 && nums[i-1] == nums[i] && !vis[i-1])) continue
```

**bitset**
[c++ bitset](https://www.cnblogs.com/magisk/p/8809922.html)
#### 4种构造函数
* bitset<4> s1; // 无参构造，默认为0
* bitset<8> s2(12); // 填充数值12后，前面填充为0, 若size < 整数， 截取后面部分
* string s = "100101"; bitset<10> s3(s); // 填充字符串后，前面填充为0, 若size < 字符串长度，截取前面部分
* char s[] = "101011"; bitset<13> s4(s); // 填充字符串后，前面填充为0，若size < 字符串长度，截取前面部分

#### 可用操作符
* ^ & | << >> ~ == != []

#### 可用函数
* count: 统计1的数量
* size：返回bitset大小
* test：返回指定下标处是否为1
* any: 是否有1
* none：是否没1
* all：是否全1
* flip： 反转
* set： 设置为1
* reset： 设置为0
* to_string
* to_ulong
* to_ullong

**201** 对[m, n]区间的数字取并
暴力取并会超时，自己也发现了数学上的规律：从高位到低位，当某一位数字不相同时，后续取并均为0
自己实现是借用了stl中的bitset数据结构，转化为bitset后，再寻找到一个不相同的数字
看了题解发现，问题可以更普适的归纳为寻找两个数字的公共前缀，当m/n不等时，不断右移，记录移动位数，再将公共前缀左移相应位数可以得到答案

**229** 摩尔投票法
通过map记录每人票数方法不符合O(1)空间复杂度要求
使用通用的摩尔投票法，可以使用O(1)空间解决问题
```
如果至多选m个代表，那他们的票数至少要超过 ⌊ 1/(m+1) ⌋ 的票数
```


### 2020.09.20

**228** 汇总区间

题目很简单，需要捋清逻辑和转折关系



### 2020.09.19

**gdb** 

https://www.cs.cmu.edu/~gilpin/tutorial/


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

