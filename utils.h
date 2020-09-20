#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cmath>

using namespace std;

template<typename T>
void printVector(vector<T>& list) {
    for (auto& v : list) {
        cout << v << " ";
    }
    cout << endl;
}

void printVector2D(vector<vector<int>>& lists) {
    for (auto& v : lists) {
        printVector(v);
    }
}

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printTree(TreeNode* root) {
    if (root == nullptr) {
        printf("null ");
        return;
    }
    printf("%d ", root->val);
    printTree(root->left);
    printTree(root->right);
}

// // unordered_map 自定义键值
// namespace std {
//     template <> //function-template-specialization
//         class hash<vector>{
//         public :
//             size_t operator()(const vector &name ) const
//             {
//                 return hash<string>()(name.first) ^ hash<string>()(name.second);
//             }
//     };
// };


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printListNodes(ListNode* root) {
    ListNode* head = root;
    while (head != nullptr) {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("end\n");
}
