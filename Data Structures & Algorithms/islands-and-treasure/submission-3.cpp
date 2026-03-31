class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c, int dist) {
        int ROWS = grid.size(), COLS = grid[0].size();
        
        // Boundary + wall check
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || grid[r][c] < dist) {
            return;
        }

        grid[r][c] = dist;

        dfs(grid, r + 1, c, dist + 1);
        dfs(grid, r - 1, c, dist + 1);
        dfs(grid, r, c + 1, dist + 1);
        dfs(grid, r, c - 1, dist + 1);
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();

        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (grid[r][c] == 0) {  // Start DFS from each gate
                    dfs(grid, r, c, 0);
                }
            }
        }
    }
};
