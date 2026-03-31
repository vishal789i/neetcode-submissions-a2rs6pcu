class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        auto ROWS = grid.size(), COLS = grid[0].size();
        int freshOranges = 0;
        queue<pair<int, int>> q;
        for (auto r = 0; r < ROWS; ++r) {
            for (auto c = 0; c < COLS; ++c) {
                if (grid[r][c] == 1) {
                    freshOranges++;
                } else if (grid[r][c] == 2) {
                    q.push({r, c});
                }
            }
        }

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int t = 0;
        while (not q.empty() and freshOranges) {
            auto size = q.size();
            while (size--) {
                auto r = q.front().first, c = q.front().second;
                q.pop();
                for (auto d : dirs) {
                    auto newR = r + d.first, newC = c + d.second;
                    if (newR < 0 or newR == ROWS or newC < 0 or newC == COLS or grid[newR][newC] != 1) {
                        continue;
                    }

                    freshOranges--;
                    grid[newR][newC] = 2;
                    q.push({newR, newC});
                }
            }
            t++;
        }

        return freshOranges == 0 ? t : -1;
    }
};
