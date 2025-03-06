#include "Trie.h"
#include "TrieNode.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Trie::Trie() {
    root = new TrieNode();
}

void Trie::insert(const string& word) {
    TrieNode* node = root;
    for (char ch : word) {
        int index = ch - 'a';
        if (node->children[index] == nullptr) {
            node->children[index] = new TrieNode();
        }
        node = node->children[index];
    }
    node->isEnd = true;
}

bool Trie::search(const string& word) {
    TrieNode* node = root;
    for (char ch : word) {
        int index = ch - 'a';
        if (node->children[index] == nullptr) {
            return false;
        }
        node = node->children[index];
    }
    return node->isEnd;
}

vector<string> Trie::getSuggestions(const string& prefix, int limit) {
    vector<string> suggestions;
    TrieNode* node = root;

    for (char ch : prefix) {
        int index = ch - 'a';
        if (node->children[index] == nullptr) {
            return suggestions;
        }
        node = node->children[index];
    }

    gatherSuggestions(node, prefix, suggestions, limit);

    return suggestions;
}

void Trie::gatherSuggestions(TrieNode* node, const string& prefix, vector<string>& suggestions, int& limit) {
    if (node->isEnd) {
        suggestions.push_back(prefix);
        limit++;
    }

    for (int i = 0; i < 26; i++) {
        if (node->children[i] != nullptr) {
            gatherSuggestions(node->children[i], prefix + char(i + 'a'), suggestions, limit);
        }
    }
}
