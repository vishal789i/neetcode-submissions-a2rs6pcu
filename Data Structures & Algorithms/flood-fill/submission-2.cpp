class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ROWS = image.size(), COLS = image[0].size();
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        function<void(int, int, int)> f = [&] (int r, int c, int srcColor) {
            image[r][c] = color;
            for (auto [dr, dc] : dirs) {
                auto newR = r + dr, newC = c + dc;
                if (newR < 0 or newR == ROWS or newC < 0 or newC == COLS) {
                    continue;
                }

                if (image[newR][newC] == srcColor and image[newR][newC] != color) {
                    f(newR, newC, srcColor);
                }
            }
        };

        f(sr, sc, image[sr][sc]);
        return image;
    }
};