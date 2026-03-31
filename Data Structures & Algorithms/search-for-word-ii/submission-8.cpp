class Solution {
    struct Node {
        bool isEndOfWord{false};
        vector<Node*> neighbors{26};
    };

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* root = new Node();
        for (auto& w : words) {
            auto cur = root;
            for (auto ch : w) {
                if (cur->neighbors[ch - 'a'] == nullptr) {
                    cur->neighbors[ch - 'a'] = new Node();
                }

                cur = cur->neighbors[ch - 'a'];
            }

            cur->isEndOfWord = true;
        }

        auto ROWS = board.size(), COLS = board[0].size();
        set<string> res;
        string op;
        function<void(int, int, Node*)> dfs = [&] (int r, int c, Node* cur) {
            if (r < 0 or r == ROWS or c < 0 or c == COLS or board[r][c] == '#') {
                return;
            }

            auto tmp = board[r][c];
            cur = cur->neighbors[tmp - 'a'];
            if (cur == nullptr) {
                return;
            }

            op.push_back(tmp);
            if (cur->isEndOfWord) {
                res.insert(op);
            }

            board[r][c] = '#';
            dfs(r + 1, c, cur);
            dfs(r - 1, c, cur);
            dfs(r, c + 1, cur);
            dfs(r, c - 1, cur);
            board[r][c] = tmp;
            op.pop_back();
        };

        for (auto r = 0; r < ROWS; ++r) {
            for (auto c = 0; c < COLS; ++c) {
                dfs(r, c, root);
            }
        }

        return vector<string>(res.begin(), res.end());
    }
};
