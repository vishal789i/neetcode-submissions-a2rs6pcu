class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int R = board.size(), C = board[0].size();
        
        function<void(int, int)> dfs = [&] (int r, int c) {
            if (r < 0 or r == R or c < 0 or c == C or board[r][c] != 'O') {
                return;
            }

            board[r][c] = 'T';
            vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            for (auto dir: dirs) {
                dfs(r + dir.first, c + dir.second);
            }
        };

        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (r == 0 or r == R - 1 or c == 0 or c == C - 1 and board[r][c] == 'O') {
                    dfs(r, c);
                }
            }
        }

        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (board[r][c] == 'T') {
                    board[r][c] = 'O';
                } else if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                }
            }
        }
    }
};
