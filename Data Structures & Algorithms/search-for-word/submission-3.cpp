class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        const int ROWS = board.size(), COLS = board[0].size();
        using State = tuple<int,int,int,vector<vector<bool>>>; 
        // (row, col, index, visited)

        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (board[r][c] != word[0]) continue;

                queue<State> q;
                q.emplace(r, c, 0, vector<vector<bool>>(ROWS, vector<bool>(COLS, false)));

                while (!q.empty()) {
                    auto [cr, cc, i, visited] = q.front();
                    q.pop();

                    if (i == word.size() - 1 && board[cr][cc] == word[i]) {
                        return true;
                    }

                    if (board[cr][cc] != word[i]) continue;

                    visited[cr][cc] = true;

                    // Explore neighbors
                    const int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
                    for (auto& d : dirs) {
                        int nr = cr + d[0], nc = cc + d[1];
                        if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && !visited[nr][nc]) {
                            q.emplace(nr, nc, i+1, visited);
                        }
                    }
                }
            }
        }

        return false;
    }
};
