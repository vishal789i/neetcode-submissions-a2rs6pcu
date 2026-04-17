class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        vector vis(ROWS + 1, vector(COLS + 1, 0));
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        auto bfs = [&] (int r, int c) {
            queue<pair<int, int>> q;
            q.push({r, c});
            int res = 0;
            while (not q.empty()) {
                auto [curR, curC] = q.front();
                q.pop();
                res++;
                for (auto [dr, dc] : dirs) {
                    auto newR = curR + dr, newC = curC + dc;
                    if (newR < 0 or newR == ROWS or newC < 0 or newC == COLS or grid[newR][newC] == 0 or vis[newR][newC] == 1) {
                        continue;
                    }
                    
                    vis[newR][newC] = 1;
                    q.push({newR, newC});
                }
            }

            return res;
        };

        int res = 0;
        for (auto r = 0; r < ROWS; ++r) {
            for (auto c = 0; c < COLS; ++c) {
                if (vis[r][c] == 0 and grid[r][c] == 1) {
                    vis[r][c] = 1;
                    res = max(res, bfs(r, c));
                }
            }
        }

        return res;
    }
};
