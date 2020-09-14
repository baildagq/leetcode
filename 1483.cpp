#include "./utils.h"



class TreeAncestor {
public:
    vector<int> parent;
    TreeAncestor(int n, vector<int>& parent) {
        this->parent = parent;
    }
    
    int getKthAncestor(int node, int k) {
        while (k > 0 && node > 0) {
            node = this->parent[node];
            k -= 1;
        }

        if (k == 0 && node >= 0) {
            return node;
        }
        return -1;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */


int main(int argc, const char** argv)
{
    // TreeAncestor* obj = new TreeAncestor(n, parent);
    // int param_1 = obj->getKthAncestor(node,k);
    return 0;
}
