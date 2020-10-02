#include "./utils.h"

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        vector<vector<pair<int, int>>> starts;
        starts.resize(26);

        int lenx = board.size();
        if (!lenx) return {};
        int leny = board[0].size();
        if (!leny) return {};

        for (int i = 0;i < lenx; i++) {
            for (int j = 0; j < lenx; j ++) {
                starts[board[i][j] - 'a'].push_back(make_pair(i, j));
            }
        }
    }
};

int main(int argc, const char** argv)
{
    vector<int> list = { 1, 2, 3, 4, 5 };
    vector<vector<int>> lists = { { -240, -657 }, { -27, -188 }, { -616, -247 } };
    printf("%d\n", Solution().maxPoints(lists));
    return 0;
}
