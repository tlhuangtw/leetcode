class TrieNode {
public:
    unordered_map<char, unique_ptr<TrieNode>> children;
    bool isEndOfWord;
    TrieNode(): isEndOfWord(false) {}
};

class WordDictionary {
private:
    unique_ptr<TrieNode> root;

    bool dfs(string& word, int index, TrieNode* node) {
        if (index == word.size()) {
            return node->isEndOfWord;
        }

        char c = word[index];
        if (c == '.') {
            for (const auto& [key, value] : node->children) {
                if (dfs(word, index + 1, value.get())) {
                    return true;
                }
            }

            return false;
        } else {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            return dfs(word, index + 1, node->children[c].get());
        }
    }
public:
    WordDictionary() {
        root = make_unique<TrieNode>();
    }
    
    void addWord(string word) {
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
        return dfs(word, 0, root.get());
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

