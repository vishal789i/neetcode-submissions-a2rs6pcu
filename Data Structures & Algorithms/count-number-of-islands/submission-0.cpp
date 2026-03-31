class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int R = grid.size(), C = grid[0].size();
        set<pair<int, int>> visited;
        int res = 0;

        function<void(int, int)> bfs = [&] (int r, int c) {
            queue<pair<int, int>> q;
            q.push({r, c});
            while (not q.empty()) {
                int r1 = q.front().first, c1 = q.front().second;
                q.pop();

                vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
                for (auto dir: dirs) {
                    auto newR = r1 + dir.first, newC = c1 + dir.second;
                    if (newR >= 0 and 
                        newR < R and 
                        newC >= 0 and 
                        newC < C and 
                        grid[newR][newC] == '1' and 
                        not visited.count({newR, newC})) {
                            q.push({newR, newC});
                            visited.insert({newR, newC});
                        }
                }
            }
        };

        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (not visited.count({r, c}) and grid[r][c] == '1') {
                    visited.insert({r, c});
                    bfs(r, c);
                    res++;
                }
            }
        }
        return res;
    }
};
