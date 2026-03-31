class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size(), freshOranges = 0;
        queue<pair<int, int>> q;
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                } else if (grid[r][c] == 1) {
                    freshOranges++;
                }
            }
        }
        
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int t = 0;
        while (not q.empty() and freshOranges > 0) {
            t++;
            int levelSize = q.size();
            for (auto i = 0; i < levelSize; ++i) {
                auto [r, c] = q.front();
                q.pop();
                for (auto& [dr, dc] : dirs) {
                    auto newR = r + dr, newC = c + dc;
                    if (newR < 0 or newR == ROWS or newC < 0 or newC == COLS or grid[newR][newC] != 1) {
                        continue;
                    }
                    
                    grid[newR][newC] = 2;
                    freshOranges--;
                    q.push({newR, newC});
                }
            }
        }
        
        return freshOranges == 0 ? t : -1;
    }
};