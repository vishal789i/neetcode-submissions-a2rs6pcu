class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int ROWS = heights.size(), COLS = heights[0].size();
        vector<vector<int>> dist(ROWS, vector<int>(COLS, INT_MAX));
        dist[0][0] = 0;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, 0, 0});
        int res = INT_MIN;
        while (not pq.empty()) {
            auto [r, c, diff] = pq.top();
            pq.pop();
            if (r == ROWS - 1 and c == COLS - 1) {
                return diff;
            }

            if (diff > dist[r][c]) {
                continue;
            }

            for (auto [dr, dc] : dirs) {
                auto newR = r + dr, newC = c + dc;
                if (newR < 0 or newC < 0 or newR == ROWS or newC == COLS) {
                    continue;
                }

                int newDiff = max(diff, abs(heights[r][c] - heights[newR][newC]));
                if (newDiff < dist[newR][newC]) {
                    dist[newR][newC] = newDiff;
                    pq.push({newR, newC, newDiff});
                }
            }
        }

        return res;
    }
};