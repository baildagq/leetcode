#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

template <typename T>
void printVector(const vector<T>& list, int size = -1)
{
    if (size == -1) {
        for (auto& v : list) {
            // cout.width(8);
            cout << v << " ";
        }
    } else {
        for (int i = 0; i < size; i++) {
            cout << list[i] << " ";
        }
    }
    cout << endl;
}

template <typename T>
void printVector2D(const vector<vector<T>>& lists)
{
    for (auto& v : lists) {
        printVector(v);
    }
}

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
    {
    }
};

TreeNode* makeTree(const vector<int>& list)
{
    TreeNode* root = new TreeNode(0);
    return root;
}

void printTree(TreeNode* root)
{
    if (root == nullptr) {
        printf("null ");
        return;
    }
    printf("%d ", root->val);
    printTree(root->left);
    printTree(root->right);
}

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printListNodes(ListNode* root)
{
    ListNode* head = root;
    while (head != nullptr) {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("end\n");
}

void printBin(int x)
{
    cout << bitset<sizeof(int) * 8>(x) << endl;
}

void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
{
    std::string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while (std::string::npos != pos2) {
        v.push_back(s.substr(pos1, pos2 - pos1));

        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if (pos1 != s.length()) {
        v.push_back(s.substr(pos1));
    }
}
