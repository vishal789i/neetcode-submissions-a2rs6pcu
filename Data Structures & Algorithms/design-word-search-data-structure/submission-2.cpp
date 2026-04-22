class WordDictionary {
    struct TrieNode {
        bool m_IsEndNode;
        map<char, TrieNode*> m_Ch2Node;
    };

    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();        
    }
    
    void addWord(string word) {
        auto curr = root;
        for (auto ch : word) {
            if (curr->m_Ch2Node[ch] == nullptr) {
                curr->m_Ch2Node[ch] = new TrieNode();
            }

            curr = curr->m_Ch2Node[ch];
        }

        curr->m_IsEndNode = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

    bool dfs(string word, int idx, TrieNode* root) {
        auto curr = root;
        for (int i = idx; i < word.size(); ++i) {
            if (word[i] == '.') {
                for (auto [ch, node] : curr->m_Ch2Node) {
                    if (node != nullptr and dfs(word, i + 1, node)) {
                        return true;
                    }
                }

                return false;
            } else {
                if (curr->m_Ch2Node[word[i]] == nullptr) {
                    return false;
                }

                curr = curr->m_Ch2Node[word[i]];
            }
        }

        return curr->m_IsEndNode;
    }
};
