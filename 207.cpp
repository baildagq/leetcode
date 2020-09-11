#include "./utils.h"

class Solution {
public:
    // 看过题解，发现自己写的方法实在有些复杂了, 思路类似广度优先搜索，但是判断条件上有比较大的问题
    // 判断是否存在拓扑图，可以通过深度优先搜索和广度优先搜索两种方法
    // 深度优先搜索通过标记三种，搜索前，搜索中，搜索完成3种状态
    // 广度优先搜索通过标记入度
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> pres = vector<vector<int>>(numCourses);
        vector<vector<int>> next = vector<vector<int>>(numCourses);
        int finishedNum = 0;

        // init
        for (auto& p: prerequisites) {
            pres[p[0]].push_back(p[1]);
            next[p[1]].push_back(p[0]);
        }
        vector<int> newFinished;
        for (int i = 0;i < numCourses; i++) {
            if (pres[i].size() == 0) {
                finishedNum += 1;
                newFinished.push_back(i);
            }
        }

        // after
        while (newFinished.size() != 0) {
            vector<int> tmp;
            for (auto& v : newFinished) {
                for (auto& k : next[v]) {
                    for (auto it = pres[k].begin(); it != pres[k].end(); it ++) {
                        if (*it == v) {
                            pres[k].erase(it);
                            break;
                        }
                    }
                    if (pres[k].size() == 0) {
                        finishedNum += 1;
                        tmp.push_back(k);
                    }
                }
            }
            newFinished = tmp;
        }
        return finishedNum == numCourses;
    }
};


int main(int argc, const char** argv)
{
    int numCourses = 5;
    vector<vector<int>> prerequisites = {{0,1}, {1,2}, {2,3}, {3,4}};
    printf("%d\n", Solution().canFinish(numCourses, prerequisites));
    return 0;
}
