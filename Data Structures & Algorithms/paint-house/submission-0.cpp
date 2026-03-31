class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        map<pair<int, int>, int> dp;
        function<int(int, int)> dfs = [&] (int i, int lastColorIdx) {
            if (i == costs.size()) {
                return 0;
            }

            if (dp.contains({i, lastColorIdx})) {
                return dp[{i, lastColorIdx}];
            }

            int res = INT_MAX;
            for (int j = 0; j < costs[i].size(); ++j) {
                if (j == lastColorIdx) {
                    continue;
                }

                res = min(res, costs[i][j] + dfs(i + 1, j));
            }

            return dp[{i, lastColorIdx}] = res;
        };

        return dfs(0, -1);
    }
};