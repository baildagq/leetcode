#include "./utils.h"



struct Node {
    int l = 0;
    int r = 0;
    int val = 0;
};

class SegmentTree {
public:
    vector<Node> tree;
    vector<int> input;
    SegmentTree(vector<int>& nums){
        this->tree = vector<Node>(4 * nums.size());
        this->input = nums;
        build(0,  0, nums.size() - 1);

        for (int i = 0; i < int(tree.size());i ++) {
            printf("%d ", tree[i].val);
        }
        printf("\n");
    }

    void build(int idx, int l, int r) {
        this->tree[idx].l = l;
        this->tree[idx].r = r;
        if (l == r) {
            this->tree[idx].val = this->input[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(2 * idx, l, mid);
        build(2 * idx + 1, mid + 1, r);
        this->tree[idx].val = max(this->tree[2 * idx].val, this->tree[2 * idx + 1].val);
    }
    
    int queryMax(int idx, int l, int r) {
        if (l <= this->tree[idx].l && this->tree[idx].r <= r) {
            return this->tree[idx].val;
        }
        int res = INT_MIN;
        if (r < this->tree[idx]. l || this->tree[idx].r < l) {
            return res;
        }
        if (this->tree[2 * idx].r >= l) {
            res = max(res, queryMax(2 * idx, l, r));
        }
        if (this->tree[2 * idx + 1].l <= r) {
            res = max(res, queryMax(2 * idx + 1, l, r));
        }
        return res;
    }
};


class Solution {
public:
    vector<int> dp; // dp[i] 表示在[i: num.size()]中能够得到的最大值
    vector<int> maxval;
    int constrainedSubsetSum(vector<int>& nums, int k) {
        dp = nums;
        SegmentTree tree(nums);
        int l, r;
        l = 0, r = 4;
        printf("max %d %d : %d\n", l, r, tree.queryMax(0, l, r));
        l = 1, r = 2;
        printf("max %d %d : %d\n", l, r, tree.queryMax(0, l, r));
        l = 2, r = 4;
        printf("max %d %d : %d\n", l, r, tree.queryMax(0, l, r));
        l = 0, r = 3;
        printf("max %d %d : %d\n", l, r, tree.queryMax(0, l, r));

        int size = nums.size();
        for (int i = size - 1; i >= 0; i--) {
            int maxval = tree.queryMax(0, i, (i+k<size) ? i+k : size - 1);
            dp[i] = max(dp[i], maxval + dp[i]);
        }
        int res = dp[0];
        for (int i = 1; i < size; i ++) {
            res = max(res, dp[i]);
        }
        return res;
    }
};


int main(int argc, const char** argv)
{
    vector<int> list = {10,2,-10,5,20};
    int k = 2;
    printf("res: %d\n", Solution().constrainedSubsetSum(list, k));
    return 0;
}
