#include <algorithm>
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

using namespace std;

int main(int argc, const char** argv)
{
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    vector<int> p2k(n, -1); // 1 对 1: place 2 kind
    map<int, vector<int>> k2p;   // 1 对 多: kind 2 place
    int currKind = 0, head = -1, tail = -1;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &head, &tail);
        head -= 1;
        tail -= 1;
        if (p2k[head] == -1 && p2k[tail] == -1) {
            // head/tail 均未分配类别
            p2k[head] = p2k[tail] = currKind;
            k2p[currKind] = { head, tail };
            currKind ++;
        } else if (p2k[head] == -1) {
            // head 未分配类别，将其类别设置为当前tail所在类别
            p2k[head] = p2k[tail];
            k2p[p2k[head]].push_back(head);
        } else if (p2k[tail] == -1) {
            // tail 未分配类别，将其类别设置为当前head所在类别
            p2k[tail] = p2k[head];
            k2p[p2k[tail]].push_back(tail);
        } else {
            // head/tail 均分配类别
            if (p2k[head] != p2k[tail]) {
                // if 类别不等，将所有类别与tail相同的节点，设置为与head相同
                int headKind = p2k[head];
                int tailKind = p2k[tail];
                for (auto place : k2p[tailKind]) {
                    p2k[place] = headKind;
                    k2p[headKind].push_back(place);
                }
                k2p[tailKind].clear();
            }
        }
    }

    for (int i = 0; i < q; i++) {
        scanf("%d %d", &head, &tail);
        head -= 1;
        tail -= 1;
        if (p2k[head] != -1 && p2k[tail] != -1 && p2k[head] == p2k[tail]) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
