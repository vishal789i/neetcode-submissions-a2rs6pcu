class Solution {
    struct TrieNode {
        bool m_IsEndNode;
        map<char, TrieNode*> m_Ch2Node;
    };

    TrieNode* m_Root;

    void addWord(string word) {
        auto curr = m_Root;
        for (auto ch: word) {
            if (curr->m_Ch2Node[ch] == nullptr) {
                curr->m_Ch2Node[ch] = new TrieNode();
            }
            curr = curr->m_Ch2Node[ch];
        }
        curr->m_IsEndNode = true;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m_Root = new TrieNode();

        for (auto word: words) {
            addWord(word);
        }

        int R = board.size();
        int C = board[0].size();

        vector<vector<int>> visited(R, vector<int>(C, false));
        unordered_set<string> res;

        function<void(TrieNode*, int, int, string)> dfs = [&] (TrieNode* root, int r, int c, string word) {
            if (r < 0 or c < 0 or r >= R or c >= C 
                or visited[r][c] 
                or root->m_Ch2Node[board[r][c]] == nullptr) {
                return;
            }

            visited[r][c] = true;
            word += board[r][c];
            root = root->m_Ch2Node[board[r][c]];

            if (root->m_IsEndNode) {
                res.insert(word);
            }

            dfs(root, r+1, c, word);
            dfs(root, r-1, c, word);
            dfs(root, r, c+1, word);
            dfs(root, r, c-1, word);

            visited[r][c] = false;
        };

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                dfs(m_Root, i, j, "");
            }
        }

        return vector<string>(res.begin(), res.end());
    }
};
