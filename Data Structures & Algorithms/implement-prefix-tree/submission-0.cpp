class PrefixTree {
    struct TrieNode {
        map<char, TrieNode*> m_Char2TrieNode;
        bool isEndNode;
    };

    TrieNode* m_Root;

public:
    PrefixTree() {
        m_Root = new TrieNode();
    }
    
    void insert(string word) {
        auto curr = m_Root;
        for (auto ch: word) {
            if (curr->m_Char2TrieNode[ch] == nullptr) {
                curr->m_Char2TrieNode[ch] = new TrieNode();
            }
            curr = curr->m_Char2TrieNode[ch];
        }
        curr->isEndNode = true;
    }
    
    bool search(string word) {
        auto curr = m_Root;
        for (auto ch: word) {
            if (curr->m_Char2TrieNode[ch] == nullptr) {
                return false;
            }
            curr = curr->m_Char2TrieNode[ch];   
        }
        return curr->isEndNode;
    }
    
    bool startsWith(string prefix) {
        auto curr = m_Root;
        for (auto ch: prefix) {
            if (curr->m_Char2TrieNode[ch] == nullptr) {
                return false;
            }
            curr = curr->m_Char2TrieNode[ch];   
        }
        return true;
    }
};
