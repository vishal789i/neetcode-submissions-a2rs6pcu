class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ROWS = image.size(), COLS = image[0].size();
        set<pair<int, int>> vis;
        int sColor = image[sr][sc];
        function<void(int, int)> dfs = [&] (int r, int c) {
            if (r < 0 or r == ROWS or c < 0 or c == COLS or image[r][c] != sColor or vis.contains({r, c})) {
                return;
            }

            vis.insert({r, c});
            image[r][c] = color;
            dfs(r + 1, c);
            dfs(r - 1, c);
            dfs(r, c + 1);
            dfs(r, c - 1);
        };

        dfs(sr, sc);
        return image;
    }
};