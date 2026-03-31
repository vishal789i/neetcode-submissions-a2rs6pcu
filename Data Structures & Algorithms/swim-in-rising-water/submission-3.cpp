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
                auto newR = r + dr, newC = c + dc;
                if (newR < 0 or newR == ROWS or newC < 0 or newC == COLS or vis.count({newR, newC})) {
                    continue;
                }

                vis.insert({newR, newC});
                minHeap.push({max(t, grid[newR][newC]), newR, newC});
            }
        }
        
        return ROWS * COLS;
    }
};