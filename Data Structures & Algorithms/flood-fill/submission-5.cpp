class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ROWS = image.size(), COLS = image[0].size(), srcColor = image[sr][sc];;
        vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        auto dfs = [&] (auto self, int r, int c) -> void {
            image[r][c] = color;
            for (auto [dr, dc] : dirs) {
                auto newR = r + dr, newC = c + dc;
                if (newR < 0 or newR == ROWS or newC < 0 or newC == COLS or image[newR][newC] != srcColor or image[newR][newC] == color) {
                    continue;
                }

                self(self, newR, newC);
            }
        };

        dfs(dfs, sr, sc);
        return image;
    }
};