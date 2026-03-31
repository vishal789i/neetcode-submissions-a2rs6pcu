class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        queue<tuple<int, int, int>> q;
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (grid[r][c] == 0) {
                    q.push({r, c, 0});
                }
            }
        }
        
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (not q.empty()) {
            auto [r, c, dist] = q.front();
            q.pop();
            for (auto [dr, dc] : dirs) {
                auto newR = r + dr, newC = c + dc;
                if (newR < 0 or newR == ROWS or newC < 0 or newC == COLS or grid[newR][newC] != INT_MAX) {
                    continue;
                }

                grid[newR][newC] = dist + 1;
                q.push({newR, newC, dist + 1});
            }
        }
    }
};
