class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int R = board.size(), C = board[0].size();
        queue<pair<int, int>> q;
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (r == 0 or r == R - 1 or c == 0 or c == C - 1 and board[r][c] == 'O') {
                    q.push({r, c});
                }
            }
        }

        while (not q.empty()) {
            auto r = q.front().first, c = q.front().second;
            q.pop();
            
            if (board[r][c] == 'O') {
                board[r][c] = 'T';
                vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
                for (auto dir: dirs) {
                    auto dr = r + dir.first, dc = c + dir.second;
                    if (dr < 0 or dr == R or dc < 0 or dc == C) {
                        continue;
                    }
                    q.push({dr, dc});
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
