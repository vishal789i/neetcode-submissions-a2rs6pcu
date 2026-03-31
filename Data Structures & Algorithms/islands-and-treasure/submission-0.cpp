class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        queue<pair<int, int>> q;
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        while (not q.empty()) {
            int r = q.front().first, c = q.front().second;
            q.pop();

            vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            for (auto dir: dirs) {
                auto newR = r + dir.first, newC = c + dir.second;
                if (newR < 0 or newR == R or newC < 0 or newC == C or
                    grid[newR][newC] != INT_MAX) {
                    continue;
                }

                grid[newR][newC] = grid[r][c] + 1;
                q.push({newR, newC});
            }
        }
    }
};
