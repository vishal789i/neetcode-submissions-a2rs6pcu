class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector arr(strs.size(), vector<int>(2, 0));
        for (int i = 0; i < strs.size(); ++i) {
            for (int j = 0; j < strs[i].size(); ++j) {
                arr[i][strs[i][j] - '0']++; // cnt of 0/1 at idx i
            }
        }

        map<tuple<int, int, int>, int> dp;
        function<int(int, int, int)> dfs = [&] (int i, int m, int n) {
            if (i == arr.size()) {
                return 0;
            }

            if (dp.contains({i, m, n})) {
                return dp[{i, m, n}];
            }

            auto res = dfs(i + 1, m, n);
            auto zeroCnt = arr[i][0], oneCnt = arr[i][1];
            if (zeroCnt <= m and oneCnt <= n) {
                res = max(res, 1 + dfs(i + 1, m - zeroCnt, n - oneCnt));
            }

            return dp[{i, m, n}] = res;
        };

        return dfs(0, m, n);
    }
};