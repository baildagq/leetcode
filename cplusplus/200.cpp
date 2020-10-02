#include "./utils.h"


class Solution {
public:
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, vector<vector<int>> points){
        int lenx = grid.size();
        int leny = grid[0].size();
        vector<int> diffx{-1, 1, 0, 0};
        vector<int> diffy{0, 0, -1, 1};
        vector<vector<int>> newPoints;

        // printVector2D(points);
        // printf("\n");

        for (auto& point : points) {
            for (int i = 0;i < 4; i++) {
                int x = point[0] + diffx[i];
                int y = point[1] + diffy[i];
                if (0 <= x && x < lenx && 0 <= y && y < leny && grid[x][y] == '1' && !visited[x][y]) {
                    visited[x][y] = true;
                    newPoints.push_back({x,y});
                }
            }
        }
        if (newPoints.size() != 0) {
            bfs(grid, visited, newPoints);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int lenx = grid.size();
        if (lenx == 0) return 0;
        int leny = grid[0].size();
        if (leny == 0) return 0;

        vector<vector<bool>> visited = vector<vector<bool>>(lenx, vector<bool>(leny, false));

        int res = 0;
        for (int i = 0;i < lenx; i ++){
            for (int j = 0; j < leny; j ++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    visited[i][j] = true;
                    res += 1;
                    bfs(grid, visited, {{i,j}});
                }
            }
        }
        return res;
    }
};


int main(int argc, const char** argv) {
    vector<vector<char>> lists = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    printf("%d\n", Solution().numIslands(lists));
    return 0;
}
