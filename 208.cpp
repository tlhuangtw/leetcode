class TrieNode {
public:
    unordered_map<char, unique_ptr<TrieNode>> children;
    bool isEndOfWord;
    TrieNode(): isEndOfWord(false) {}
};

class Trie {
private:
    unique_ptr<TrieNode> root;
public:
    Trie() {
        root = make_unique<TrieNode>();
    }
    
    void insert(string word) {
        TrieNode* cur = root.get();

        for (const auto& c : word) {
            if (cur->children.find(c) == cur->children.end()) {
                cur->children[c] = make_unique<TrieNode>();
            }
            cur = cur->children[c].get();
        }

        cur->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = findNode(word);
        return node != nullptr && node->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        return findNode(prefix) != nullptr;
    }
private:
    TrieNode* findNode(string word) {
        TrieNode* cur = root.get();

        for (const auto& c : word) {
            if (cur->children.find(c) == cur->children.end()) {
                return nullptr;              
            }
            cur = cur->children[c].get();
        }

        return cur;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

