#ifndef TRIENODE_H
#define TRIENODE_H

#include <vector>
#include <string>


using namespace std;

struct TrieNode {
    bool isEnd;
    vector<TrieNode*> children;

    TrieNode();
};

#endif  
