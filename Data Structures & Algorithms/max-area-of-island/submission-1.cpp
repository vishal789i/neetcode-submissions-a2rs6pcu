class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        
        auto&& bfs = [&] (int r, int c) {
            grid[r][c] = 0;
            int count = 0;
            queue<pair<int, int>> q;
            q.push({r, c});
            while (not q.empty()) {
                auto r1 = q.front().first, c1 = q.front().second;
                q.pop();
                count++;
                vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
                for (auto dir: dirs) {
                    auto newR = r1 + dir.first, newC = c1 + dir.second;
                    if (newR >= 0 and 
                        newR < R and 
                        newC >= 0 and 
                        newC < C and 
                        grid[newR][newC] == 1) {
                            q.push({newR, newC});
                            grid[newR][newC] = 0;
                        }
                }
            }
            return count;
        };

        auto maxCount = 0;
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (grid[r][c] == 1) {
                    maxCount = max(maxCount, bfs(r, c));
                }
            }
        }

        return maxCount;
    }
};
