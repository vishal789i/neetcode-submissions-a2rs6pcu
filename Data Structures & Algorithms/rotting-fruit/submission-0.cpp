class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        queue<pair<int, int>> q;
        int freshOranges = 0;
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                } else if (grid[r][c] == 1) {
                    freshOranges++;
                }
            }
        }

        int t = 0;
        while (not q.empty() and freshOranges > 0) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                auto r = q.front().first, c = q.front().second;
                q.pop();

                vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
                for (auto dir: dirs) {
                    auto newR = r + dir.first, newC = c + dir.second;
                    if (newR < 0 or newR == R or newC < 0 or newC == C or
                        grid[newR][newC] != 1 ) {
                        continue;
                    }

                    grid[newR][newC] = 2;
                    freshOranges--;
                    q.push({newR, newC});
                }
            }
            t++;
        }

        return freshOranges == 0 ? t : -1;
    }
};
