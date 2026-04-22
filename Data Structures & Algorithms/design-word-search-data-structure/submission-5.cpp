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
        function<bool(int, TrieNode*)> dfs = [&] (int i, TrieNode* cur) {
            for (int j = i; j < word.size(); ++j) {
                if (word[j] == '.') {
                    for (auto [ch, node] : cur->m_Ch2Node) {
                        if (node != nullptr and dfs(j + 1, node)) {
                            return true;
                        }
                    }

                    return false;
                }

                if (cur->m_Ch2Node[word[j]] == nullptr) {
                    return false;
                }

                cur = cur->m_Ch2Node[word[j]];
            }

            return cur->m_IsEndNode;
        };

        return dfs(0, root);
    }
};
