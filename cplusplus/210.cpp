#include "./utils.h"

class Solution {
public:
    bool valid = true;
    vector<int> stack;
    vector<int> status; // 0: not visited, 1: visiting, 2: visited
    vector<vector<int>> outs;

    void dfs(int i)
    {
        if (this->status[i] == 2) {
            return;
        }

        if (status[i] == 1) {
            this->valid = false;
            return;
        }

        this->status[i] = 1;
        for (auto& v : outs[i]) {
            if (this->status[v] == 1) {
                this->valid = false;
                return;
            } else {
                dfs(v);
                if (!this->valid) {
                    return;
                }
            }
        }
        this->status[i] = 2;
        this->stack.push_back(i);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        status.resize(numCourses);
        outs.resize(numCourses);

        for (auto& edge : prerequisites) {
            outs[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            dfs(i);
        }

        reverse(stack.begin(), stack.end());
        if (!this->valid) {
            return {};
        };
        return stack;
    }
};

int main(int argc, const char** argv)
{
    int numCourses = 3;
    vector<vector<int>> pre = { { 0, 2 }, { 1, 2 }, { 2, 0 } };
    vector<int> res = Solution().findOrder(numCourses, pre);
    printVector(res);
    return 0;
}
