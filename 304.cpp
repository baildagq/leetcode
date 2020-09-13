#include "./utils.h"

class NumMatrix {
public:
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix)
    {
        int lenx = matrix.size();
        if(!lenx) return;
        int leny = matrix[0].size();
        if(!leny) return;

        dp.resize(lenx + 1, vector<int>(leny + 1, 0));
        for (int i = 0; i < lenx; i++) {
            int sum = 0;
            for (int j = 0; j < leny; j ++) {
                sum += matrix[i][j];
                dp[i+1][j+1] = dp[i][j+1] + sum;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        if (row2 < row1 || col2 < col1) return 0;
        return dp[row2 + 1][col2 + 1] - dp[row2 + 1][col1] - dp[row1][col2 + 1] + dp[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main(int argc, const char** argv)
{
    vector<vector<int>> matrix = {
        { 3, 0, 1, 4, 2 },
        { 5, 6, 3, 2, 1 },
        { 1, 2, 0, 1, 5 },
        { 4, 1, 0, 1, 7 },
        { 1, 0, 3, 0, 5 }
    };
    NumMatrix* obj = new NumMatrix(matrix);
    printf("%d\n", obj->sumRegion(2, 1, 2, 1));
    printf("%d\n", obj->sumRegion(2, 1, 4, 3));
    printf("%d\n", obj->sumRegion(1, 1, 2, 2));
    printf("%d\n", obj->sumRegion(1, 2, 2, 4));
    return 0;
}
