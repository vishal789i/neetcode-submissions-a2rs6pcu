class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        if (grid[0][0] == 1 or grid[ROWS - 1][COLS - 1] == 1) {
            return -1;
        }

        int pathLen = 0, res = INT_MAX;
        set<pair<int, int>> vis;
        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<pair<int, int>> dirs = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
        while (not q.empty()) {
            pathLen++;
            int size = q.size();
            while (size--) {
                auto [r, c] = q.front();
                q.pop();
                if (r == ROWS - 1 and c == COLS - 1) {
                    res = min(res, pathLen);
                }

                for (auto [dr, dc] : dirs) {
                    auto newR = r + dr, newC = c + dc;
                    if (newR >= 0 and newR < ROWS and newC >= 0 and newC < COLS and not vis.contains({newR, newC}) and grid[newR][newC] == 0) {
                        vis.insert({newR, newC});
                        q.push({newR, newC});
                    }
                }
            }
        }
        
        return res == INT_MAX ? -1 : res;
    }
};