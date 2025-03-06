#ifndef TRIE_H
#define TRIE_H

#include "TrieNode.h"
#include <vector>
#include <string>


using namespace std;

class Trie {
private:
    TrieNode* root;

public:
    Trie();
    void insert(const string& word);
    bool search(const string& word);
    vector<string> getSuggestions(const string& prefix, int limit);

    TrieNode* getRoot() const {
        return root;
    }

private:
    void gatherSuggestions(TrieNode* node, const string& prefix, vector<string>& suggestions, int& limit);
};

#endif  
