class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        auto ROWS = grid.size(), COLS = grid[0].size();
        queue<pair<int, int>> q;
        for (auto r = 0; r < ROWS; ++r) {
            for (auto c = 0; c < COLS; ++c) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (not q.empty()) {
            auto size = q.size();
            while (size--) {
                auto r = q.front().first, c = q.front().second;
                q.pop();

                for (auto dir : dirs) {
                    auto newR = r + dir.first, newC = c + dir.second;
                    if (newR < 0 or newR == ROWS or newC < 0 or newC == COLS or 
                        grid[newR][newC] != INT_MAX) {
                        continue;
                    }

                    grid[newR][newC] = 1 + grid[r][c];
                    q.push({newR, newC});
                }
            }
        }
    }
};
