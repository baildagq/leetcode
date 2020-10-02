#include <iostream>
#include <cstdlib>
#include <stack>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <climits>
#include "./utils.h"



class Solution {
private:
    vector<vector<int>> connect;
public:
    /*
     * 当前算法的改进思路，不用connet进行标志位判断，而是将联通的点设为'A'
     * 这样可以最后一轮修改时将'O'(没有被改变的)变成'X', 'A'变成'O'即可
     * 进行边界判断上，可以写的更优雅，现在写法思路是保证不会进入非法点，另一种思路进入点如果是非法点退出，更具有普适性，也更自然
     */
    void dfs(vector<vector<char>>& board, int x, int y) {
        if (connect[x][y] == 1 || board[x][y] == 'X') return;
        connect[x][y] = 1;
        if (x-1 >= 0) dfs(board, x-1, y);
        if (x+1 < board.size()) dfs(board, x+1, y);
        if (y-1 >= 0) dfs(board, x, y-1);
        if (y+1 < board[0].size()) dfs(board, x, y+1);
    }
    void solve(vector<vector<char>>& board) {
        int lenx = board.size();
        if (lenx <= 2) return;
        int leny = board[0].size();
        if (leny <= 2) return;
        connect = vector<vector<int>>(lenx, vector<int>(leny, 0));
        for (int i = 0;i < lenx; i ++) {
            dfs(board, i, 0);
            dfs(board, i, leny-1);
        }
        for (int i = 0;i < leny;i++){
            dfs(board, 0, i);
            dfs(board, lenx-1, i);
        }
        for (int i = 0;i < lenx;i ++) {
            for (int j = 0;j < leny;j ++) {
                if (board[i][j] == 'O' && connect[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};


int main(int argc, const char** argv) {
    vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    Solution().solve(board);
    for (int i = 0;i < 4;i ++) {
        for (int j=0;j<4;j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}
