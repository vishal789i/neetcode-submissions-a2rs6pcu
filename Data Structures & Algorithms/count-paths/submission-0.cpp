class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        int count = 0;
        set<pair<int, int>> vis;
        function<void(int, int)> dfs = [&] (int r, int c) {
            if (r == m - 1 and c == n - 1) {
                count++;
                return;
            }

            vector<pair<int, int>> dirs = {{0, 1}, {1, 0}};
            for (auto it : dirs) {
                int newR = it.first + r, newC = it.second + c;
                if (newR < 0 or newR == m or newC < 0 or newC == n or vis.count({r, c})) {
                    continue;
                }

                vis.insert({r, c});
                dfs(newR, newC);
                vis.erase({r, c});
            }
        };

        dfs(0, 0);
        return count;
    }
};
