class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        auto ROWS = board.size(), COLS = board[0].size();
        function<bool(int, int, int)> dfs = [&] (int r, int c, int i) {
            if (i == word.size()) {
                return true;
            }

            if (r < 0 or r >= ROWS or c < 0 or c >= COLS or board[r][c] == '#') {
                return false;
            }

            bool res = false;
            if (board[r][c] == word[i]) {
                auto temp = board[r][c];
                board[r][c] = '#';
                res = dfs(r + 1, c, i + 1) or 
                      dfs(r - 1, c, i + 1) or 
                      dfs(r, c + 1, i + 1) or 
                      dfs(r, c - 1, i + 1);
                board[r][c] = temp;
            }

            return res;
        };

        for (auto r = 0; r < ROWS; ++r) {
            for (auto c = 0; c < COLS; ++c) {
                if (dfs(r, c, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};
