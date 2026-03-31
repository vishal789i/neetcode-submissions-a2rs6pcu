class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int R = grid.size(), C = grid[0].size();
        set<pair<int, int>> visited;
        int res = 0;

        auto&& bfs = [&] (int r, int c) {
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

        function<void(int, int)> dfs = [&] (int r, int c) {
            if (r < 0 or 
                r >= R or 
                c < 0 or 
                c >= C or 
                grid[r][c] != '1' or 
                visited.count({r, c})) {
                return;
            }

            vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            visited.insert({r, c});
            for (auto dir: dirs) {
                auto newR = r + dir.first, newC = c + dir.second;
                dfs(newR, newC);
            }
        };

        auto&& dfs2 = [&] (int r, int c) {
            deque<pair<int, int>> dq;
            dq.push_back({r, c});
            while (not dq.empty()) {
                int r1 = dq.back().first, c1 = dq.back().second;
                dq.pop_back();

                vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
                for (auto dir: dirs) {
                    auto newR = r1 + dir.first, newC = c1 + dir.second;
                    if (newR >= 0 and 
                        newR < R and 
                        newC >= 0 and 
                        newC < C and 
                        grid[newR][newC] == '1' and 
                        not visited.count({newR, newC})) {
                            dq.push_back({newR, newC});
                            visited.insert({newR, newC});
                        }
                }
            }
        };


        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (grid[r][c] == '1' and visited.count({r, c}) == 0) {
                    dfs2(r, c);
                    res++;
                }
            }
        }
        return res;
    }
};
