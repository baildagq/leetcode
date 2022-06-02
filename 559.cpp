#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
public:
  // dfs
  int maxDepth(Node *root) {
    if (root == nullptr) {
      return 0;
    }
    
    auto result = 0;
    for (auto child : root->children) {
        result = std::max(result, maxDepth(child));
    }
    return 1 + result;
  }
};

int main() { return 0; }