class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int ROWS = board.size(), COLS = board[0].size();
        queue<pair<int, int>> q;
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (r == 0 or c == 0 or r == ROWS - 1 or c == COLS - 1) {
                    if (board[r][c] == 'O') {
                        q.push({r, c});
                    }
                }
            }
        }

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (not q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            board[r][c] = '#';
            for (auto [dr, dc] : dirs) {
                auto newR = r + dr, newC = c + dc;
                if (newR < 0 or newR == ROWS or newC < 0 or newC == COLS or board[newR][newC] != 'O') {
                    continue;
                }

                q.push({newR, newC});
            }
        }

        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                } else if (board[r][c] == '#') {
                    board[r][c] = 'O';
                }
            }
        }
    }
};
