class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& rooms) {
        int ROWS = rooms.size(), COLS = rooms[0].size();
        queue<tuple<int, int, int>> q;
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (rooms[r][c] == 0) {
                    q.push({r, c, 0});
                }
            }
        }

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (not q.empty()) {
            auto [r, c, dist] = q.front();
            q.pop();
            for (auto& [dr, dc] : dirs) {
                auto newR = r + dr, newC = c + dc;
                if (newR >= 0 and newR < ROWS and newC >= 0 and newC < COLS and rooms[newR][newC] == INT_MAX) {
                    rooms[newR][newC] = dist + 1;
                    q.push({newR, newC, dist + 1});
                }
            }
        }
    }
};
