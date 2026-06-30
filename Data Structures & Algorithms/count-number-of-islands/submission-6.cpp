class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        auto bfs = [&] (int r, int c) {
            queue<pair<int, int>> q;
            q.push({r, c});
            while (not q.empty()) {
                auto [curR, curC] = q.front();
                q.pop();
                for (auto [dr, dc] : dirs) {
                    auto newR = curR + dr, newC = curC + dc;
                    if (newR < 0 or newR == ROWS or newC < 0 or newC == COLS or grid[newR][newC] == '0') {
                        continue;
                    }

                    grid[newR][newC] = '0';
                    q.push({newR, newC});
                }
            }
        };

        int res = 0;
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (grid[r][c] == '1') {
                    res++;
                    bfs(r, c);
                }
            }
        }

        return res;
    }
};
