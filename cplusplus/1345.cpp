#include <iostream>
#include <cstdlib>
#include <stack>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> visited;
    vector<int> arr;
    map<int, vector<int>> val2sub;

    int bfs(vector<int>& startlist) {
        vector<int> newStartList;
        for(auto& start:startlist) {
            // i-1
            if (start-1 >= 0 && visited[start-1] == 0) {
                if (start-1 == 0) {
                    return 1;
                }
                visited[start-1] = 1;
                newStartList.push_back(start-1);
            }
            // i+1
            if (start+1 < arr.size() && visited[start+1] == 0) {
                if (start+1 == 0) {
                    return 1;
                }
                visited[start+1] = 1;
                newStartList.push_back(start+1);
            }
            // j : arr[i] = arr[j] && i!=j
            for (auto& p : val2sub[arr[start]]) {
                if (p != start && visited[p] == 0) {
                    if (p == 0) {
                        return 1;
                    }
                    visited[p] = 1;
                    newStartList.push_back(p);
                }
            }
        }
        return 1 + bfs(newStartList);
    }

    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) {
            return 0;
        }
        // make val2sub
        for (int i = 0; i < n; i ++) {
            if (val2sub.count(arr[i]) == 0) {
                val2sub[arr[i]] = vector<int>();
            }
            val2sub[arr[i]].push_back(i);
        }
        this->visited = vector<int>(n, 0);
        this->arr = arr;

        visited[n-1] = 1;
        vector<int> startList = {n-1};
        return bfs(startList);
    }
};

int main(int argc, const char** argv) {
    // vector<int> arr = {100,-23,-23,404,100,23,23,23,3,404};
    vector<int> arr = {11,22,7,7,7,7,7,7,7,22,13};
    printf("%d\n", Solution().minJumps(arr));
    return 0;
}
