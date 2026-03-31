class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int ROWS = grid.size(), COLS = grid[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;
        minHeap.push({grid[0][0], 0, 0});
        set<pair<int, int>> vis;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (not minHeap.empty()) {
            auto [t, r, c] = minHeap.top();
            minHeap.pop();
            if (r == ROWS - 1 and c == COLS - 1) {
                return t;
            }

            for (auto& [dr, dc] : dirs) {
                auto neiR = r + dr, neiC = c + dc;
                if (neiR < 0 or neiR == ROWS or neiC < 0 or neiC == COLS or vis.count({neiR, neiC})) {
                    continue;
                }

                vis.insert({neiR, neiC});
                minHeap.push({max(t, grid[neiR][neiC]), neiR, neiC});
            }
        }
        
        return ROWS * COLS;
    }
};