#include "./utils.h"

class Node {
public:
    bool isWord;
    map<char, Node*> next;
    Node(bool _isWord = false) : isWord(_isWord) {}
};

class Trie {
public:
    /** Initialize your data structure here. */
    int size = 0;
    Node* root = new Node();
    Trie() {}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* curr = this->root;
        for (auto& c : word) {
            if (curr->next.find(c) == curr->next.end()) {
                curr->next.insert(make_pair(c, new Node()));
            }
            curr = curr->next[c];
        }
        if (!curr->isWord) {
            curr->isWord = true;
            size ++;
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* curr = root;
        for (auto& c : word) {
            if (curr->next.find(c) == curr->next.end()) {
                return false;
            }
            curr = curr->next[c];
        }
        return curr->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* curr = root;
        for (auto& c : prefix) {
            if (curr->next.find(c) == curr->next.end()) {
                return false;
            }
            curr = curr->next[c];
        }
        return true;
    }
};

/*
 * 本实现为为将trie树节点与trie进行分离，trie树负责组织节点，实现插入，查找功能
 * 看到的一个更好实现是trie树即节点，同时不用map进行存储，而是直接创建长度为26的数组保存新建的trie树节点
 */

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


int main(int argc, const char** argv)
{
    Trie* obj = new Trie();
    obj->insert("abcd");
    printf("%d ", obj->search("abcde"));
    printf("%d ", obj->search("abc"));
    printf("%d ", obj->search("abcd"));
    printf("%d ", obj->startsWith("ab"));
    printf("\n");
    return 0;
}
