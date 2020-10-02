#include "./utils.h"

/*
 * method-1: 没有采用记忆化方案，每次都从查询节点一直遍历到目标根节点
 * method-2: 采用记忆化，从查询点到目标根节点的路径中，但是仍然超时
 * method-3: 猜测应该采用数学方法？？ 但是感觉和第一种应该没有差别
 * real method: binary lifting 倍增
 */


// method-2
// class TreeAncestor {
// public:
//     vector<int> parent;
//     vector<unordered_map<int, int>> record;
//     TreeAncestor(int n, vector<int>& parent) {
//         this->parent = parent;
//         this->record = vector<unordered_map<int, int>>(n);
//     }

//     int getKthAncestor(int node, int k) {
//         // 找到之前遍历时记录过的node的k个祖先
//         if (this->record[node].find(k) != this->record[node].end()) {
//             return this->record[node][k];
//         }
//         // 未遍历过，进行dfs寻找
//         // 1. 成功抵达边界情况
//         if (k == 0 && node >= 0) {
//             this->record[node][k] = node;
//             return this->record[node][k];
//         }
//         // 2. dfs路径中
//         if (k > 0 && node > 0) {
//             this->record[node][k] = getKthAncestor(this->parent[node], k - 1);
//             return this->record[node][k];
//         }
//         // 3. k > 0 && node == 0，抵达根节点而k仍有剩余
//         return -1;
//     }
// };


class TreeAncestor {
    vector<vector<int>> dp; // dp[i][j] 表示从当前节点，向上找 2^j 后的节点
public:
    TreeAncestor(int n, vector<int>& parent) {
        int size = parent.size();
        this->dp = vector<vector<int>>(size, vector<int>(16, -1));
        for (int i = 0;i < size;i ++) {
            this->dp[i][0] = parent[i];
        }
        for (int j = 1;i < 16; j ++) {
            for (int i = 0; i < size; i++) {
                if (this->dp[i][j-1] != -1) {
                    this->dp[i][j] = this->dp[this->dp[i][j-1]][j-1];
                }
            }
        }
    }
    int getKthAncestor(int node, int k) {
        for (int i = 0;i < 16; i++) {
            if (k & (1 << i)) {
                if (node >= 0) {
                    node = this->dp[node][i];
                }
                else {
                    return -1;
                }
            }
        }
        return node;
    }
};



/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */


int main(int argc, const char** argv)
{
    vector<int> parent;
    // TreeAncestor* obj = new TreeAncestor(n, parent);
    // int param_1 = obj->getKthAncestor(node,k);
    return 0;
}
