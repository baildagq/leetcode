#include "./utils.h"

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        vector<int> res;
        int size = nums.size();
        int limit = size / 3;

        /*
        // method-1: map记录投票数量，满足O(n)时间复杂度要求，不满足O(1)空间复杂度要求
        map<int, int> record;
        for (auto v : nums) {
            if (record.find(v) != record.end()) {
                record[v] += 1;
            } else {
                record[v] = 1;
            }
        }

        for (auto v : record) {
            if (v.second > limit) {
                res.push_back(v.first);
            }
        }
        */

        // method-2: 摩尔投票法，通过抵消票数，来找出可能的答案，再通过归纳可能票数确定最终答案
        vector<pair<int, int>> record;
        for (auto v : nums) {
            if (record.size() == 0) {
                record.push_back(make_pair(v, 1));
                continue;
            }
            if (record.size() == 1) {
                if (v == record[0].first) {
                    record[0].second ++;
                } else {
                    record.push_back(make_pair(v, 1));
                }
                continue;
            }
            bool haveSame = false;
            for (auto& pair : record) {
                if (v == pair.first) {
                    pair.second++;
                    haveSame = true;
                    break;
                }
            }
            if (!haveSame) {
                bool haveZero = false;
                for (auto& pair : record) {
                    if (pair.second == 0) {
                        pair.first = v;
                        pair.second = 1;
                        haveZero = true;
                        break;
                    }
                }
                if (!haveZero) {
                    for (auto& pair : record) {
                        pair.second--;
                    }
                }
            }
        }
        for (auto& pair : record) {
            pair.second = 0;
        }
        for (auto v : nums) {
            for (auto & pair : record) {
                if (pair.first == v) {
                    pair.second ++;
                }
            }
        }
        for (auto& pair : record) {
            if (pair.second > limit) {
                res.push_back(pair.first);
            }
        }
        return res;
    }
};

int main(int argc, const char** argv)
{
    vector<int> list = {1,1,1,3,3,2,2,2};
    vector<int> res = Solution().majorityElement(list);
    printVector(res);
    return 0;
}
