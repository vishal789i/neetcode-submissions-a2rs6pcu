class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int N = grid.size();
        auto invalid = [&] (int r, int c) {
            return r < 0 or r == N or c < 0 or c == N;
        };

        set<pair<int, int>> vis;
        vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        auto dfs = [&] (auto&& self, int r, int c) {
            if (invalid(r, c) or vis.contains({r, c}) or not grid[r][c]) {
                return;
            }

            vis.insert({r, c});
            for (auto [dr, dc] : dirs) {
                self(self, r + dr, c + dc);
            }
        };

        auto bfs = [&] (int r, int c) {
            queue<pair<int, int>> q(vis.begin(), vis.end());
            int res = 0;
            while (not q.empty()) {
                int size = q.size();
                while (size--) {
                    auto [curR, curC] = q.front();
                    q.pop();
                    for (auto [dr, dc] : dirs) {
                        auto newR = curR + dr, newC = curC + dc;
                        if (invalid(newR, newC) or vis.contains({newR, newC})) {
                            continue;
                        }

                        if (grid[newR][newC]) {
                            return res;
                        }

                        q.push({newR, newC});
                        vis.insert({newR, newC});
                    }
                }
                
                res++;
            }

            return N;
        };

        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                if (grid[r][c]) {
                    dfs(dfs, r, c);
                    return bfs(r, c);
                }
            }
        }

        return N;
    }
};