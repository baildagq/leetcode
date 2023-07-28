#include "./common.h"
#include <utility>
/*
 * @lc app=leetcode.cn id=2050 lang=cpp
 *
 * [2050] 并行课程 III
 */

// @lc code=start
class Solution {
public:
  int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time) {
    int res = 0;
    std::vector<std::vector<int>> workset;
    std::map<int, std::vector<int>> idx2next;
    std::map<int, int> idx2prevcnt;
    std::map<int, int> idx2prevmax;
    // pre-process
    for (auto idx = 1; idx <= n; idx ++) {
        idx2next[idx] = std::vector<int>{};
        idx2prevcnt[idx] = 0;
        idx2prevmax[idx] = 0;
    }
    for (auto& relation : relations) {
        auto prev = relation[0];
        auto next = relation[1];
        idx2next[prev].push_back(next);
        idx2prevcnt[next] += 1;
    }
    // init
    for (auto iter = idx2prevcnt.begin(); iter != idx2prevcnt.end(); iter ++)
    {
        // work_queue.push({0, iter->first, iter->second});
        if (iter->second == 0) {
            workset.push_back({0, iter->first});
        }
    }
    while (!workset.empty()) {
        std::vector<std::vector<int>> new_workset;
        for (auto iter = workset.begin(); iter != workset.end(); iter ++) {
            std::vector<int> item = *iter;
            // std::cout << "curwork: " << item[1] << " ";
            auto cur_work_finish_time = item[0] + time[item[1] - 1];
            res = std::max(res, cur_work_finish_time);
            for (auto next : idx2next[item[1]]) {
                idx2prevcnt[next] -= 1;
                idx2prevmax[next] = std::max(idx2prevmax[next], cur_work_finish_time);
                if (idx2prevcnt[next] == 0) {
                    new_workset.push_back({idx2prevmax[next], next});
                }
            }
        }
        // std::cout << std::endl;
        workset = new_workset;
    }
    return res;
  }
};
// @lc code=end

int main() {
  Solution solu;
  int n = 5;
  vector<vector<int>> relations{{1, 5}, {2, 5}, {3, 5}, {3, 4}, {4, 5}};
  vector<int> time{1, 2, 3, 4, 5};
//   int n = 3;
//   vector<vector<int>> relations{{1, 3}, {2, 3}};
//   vector<int> time{3, 2, 5};
  std::cout << solu.minimumTime(n, relations, time) << std::endl;
}
