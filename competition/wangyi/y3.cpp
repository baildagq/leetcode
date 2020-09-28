#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main(int argc, const char** argv)
{
    int _N;
    cin >> _N;
    for (int _i = 0; _i < _N; _i ++) {
        int N, D, M;
        cin >> N >> D;
        vector<vector<int>> x(N, vector<int>(D, -1));
        vector<int> y(N, -1);
        for (int i = 0;i < N;i ++) {
            for (int j = 0; j < D; j++) {
                cin >> x[i][j];
            }
            cin >> y[i];
        }
        cin >> M;
        vector<vector<vector<Pair<int, int>>>> nodesInfo(4, vector<vector<Pair<int, int>>>(16));
        vector<vector<int>> nodesValue(4, vector<int>(16, 0));
        int totalLevel = 4;
        int hiddenLevel = 1;

        for (int i = 0;i < M; i++) {
            string in, out;
            int weight, kIn, levelOut, kOut;
            cin >> in >> out >> weight;
            if (in[0] == 'i') {
                if (in.length() == 7) {
                    kIn = in[6] - '0';
                }
                if (in.length() == 8) {
                    kIn = (in[6] - '0') * 10 + in[7];
                }
            }
            if (in[0] == 'h') {
                if (in.length() == 10) {
                    kIn = in[9] - '0';
                }
                if (in.length() == 11) {
                    kIn = (in[9] - '0') * 10 + in[10];
                }
            }
            if (out[0] == 'h') {
                levelOut = in[7];
                if (levelOut == 2) {
                    hiddenLevel = 2;
                }
                if (in.length() == 10) {
                    kOut = in[9] - '0';
                }
                if (in.length() == 11) {
                    kOut = (in[9] - '0') * 10 + in[10];
                }
            }
            if (out[0] == 'o') {
                levelOut = 3;
                if (in.length() == 10) {
                    kOut = in[9] - '0';
                }
                if (in.length() == 11) {
                    kOut = (in[9] - '0') * 10 + in[10];
                }
            }
            if (nodesInfo[levelOut][kOut].size() == 0) {
                nodesInfo[levelOut][kOut] = {kIn};
                nodesWeig[levelOut][kOut] = {weight};
            } else {
                nodesInfo[levelOut][kOut].push_back(kIn);
                nodesWeig[levelOut][kOut].push_back(weight);
            }
        }

        if (hiddenLevel == 1) {
            totalLevel = 3;
            nodesInfo[2] = nodesInfo[3];
            nodesWeig[2] = nodesWeig[3];
        }
        
        // losscur
        int LOSS = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < D; j++) {
                nodesValue[0][j] = x[i][j];
            }
            for (int level = 1; level <= totalLevel; level++) {
                for (int j = 0;j < 16; j++) {
                    nodesValue[level][j] = 0;
                    for (int i = 0;i < nodesInfo[level][j].size(); i ++) {
                    }
                }
            }
        }
    }
    return 0;
}
