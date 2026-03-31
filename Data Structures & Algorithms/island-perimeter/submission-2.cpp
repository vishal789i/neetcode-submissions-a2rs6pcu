class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        auto ROWS = grid.size(), COLS = grid[0].size();
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        queue<pair<int, int>> q;
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (grid[r][c] == 1) {
                    q.push({r, c});
                }
            }
        }

        int res = 0;
        while (not q.empty()) {
            int size = q.size();
            for (auto i = 0; i < size; ++i) {
                int r = q.front().first, c = q.front().second;
                q.pop();

                if (grid[r][c] == -1) {
                    continue;
                }

                grid[r][c] = -1;

                for (auto dir : dirs) {
                    auto newR = r + dir.first, newC = c + dir.second;
                    if (newR < 0 or newR == ROWS or newC < 0 or newC == COLS or grid[newR][newC] == 0) {
                        res++;
                        continue;
                    }

                    q.push({newR, newC});
                }
            }
        }

        return res;
    }
};