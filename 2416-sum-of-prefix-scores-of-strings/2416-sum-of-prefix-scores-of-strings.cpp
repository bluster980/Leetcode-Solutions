#include <vector>
#include <string>
#include <unordered_map>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    int prefixCount = 0; 

    ~TrieNode() {
        for (auto& child : children) {
            delete child.second;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        delete root; 
    }

    void insert(const std::string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
            node->prefixCount++; 
        }
    }

    int getPrefixScore(const std::string& word) {
        TrieNode* node = root;
        int score = 0;
        for (char ch : word) {
            if (node->children.find(ch) != node->children.end()) {
                node = node->children[ch];
                score += node->prefixCount; 
            }
        }
        return score;
    }
};

class Solution {
public:
    std::vector<int> sumPrefixScores(std::vector<std::string>& words) {
        Trie trie;

        for (const auto& word : words) {
            trie.insert(word);
        }

        std::vector<int> ans(words.size());
        for (int i = 0; i < words.size(); i++) {
            ans[i] = trie.getPrefixScore(words[i]);
        }

        return ans;
    }
};
