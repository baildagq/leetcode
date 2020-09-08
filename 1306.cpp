#include <iostream>
#include <cstdlib>
#include <stack>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> visited;
    vector<int> arr;
    int size;

    bool bfs(vector<int> start){
        // printf("start: ");
        vector<int> newstart;
        for (auto& p : start) {
            // printf("%d ", p);
            if (0 <= p+arr[p] && p+arr[p] < this->size && visited[p+arr[p]] == 0) {
                if (arr[p+arr[p]] == 0) {
                    return true;
                } else {
                    newstart.push_back(p+arr[p]);
                    visited[p+arr[p]] = 1;
                }
            } 
            if (0 <= p-arr[p] && p-arr[p] < this->size && visited[p-arr[p]] == 0) {
                if (arr[p-arr[p]] == 0) {
                    return true;
                } else {
                    newstart.push_back(p-arr[p]);
                    visited[p-arr[p]] = 1;
                }
            } 
        }
        // printf("\n");
        if (newstart.size() > 0) {
            return bfs(newstart);
        }
        return false;
    }

    bool canReach(vector<int>& arr, int start) {
        this->size = arr.size();
        if (this->size == 0) {
            return true;
        }
        visited = vector<int>(this->size, 0);
        this->arr = arr;
        return bfs({start});

        // for (int i = 0;i < this->size; i ++) {
        //     // printf("%d %d\n", arr[i], visited[i]);
        //     if (arr[i] == 0 && visited[i] == 0) {
        //         return false;
        //     }
        // }
        // return true;
    }
};

int main(int argc, const char** argv) {
    vector<int> arr = {0,3,0,6,3,3,4};
    int start = 6;
    printf("%d\n", Solution().canReach(arr, start));
    return 0;
}
