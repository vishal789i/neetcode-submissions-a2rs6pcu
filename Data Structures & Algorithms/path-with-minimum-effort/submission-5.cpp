class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int ROWS = heights.size(), COLS = heights[0].size();
        set<pair<int, int>> vis;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, 0, 0});
        while (not pq.empty()) {
            auto [diff, r, c] = pq.top();
            pq.pop();
            if (r == ROWS - 1 and c == COLS - 1) {
                return diff;
            }

            if (vis.contains({r, c})) {
                continue;
            }

            vis.insert({r, c});
            for (auto [dr, dc] : dirs) {
                auto newR = r + dr, newC = c + dc;
                if (newR < 0 or newC < 0 or newR == ROWS or newC == COLS) {
                    continue;
                }

                pq.push({max(diff, abs(heights[r][c] - heights[newR][newC])), newR, newC});
            }
        }

        return 0;
    }
};