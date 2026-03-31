class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        map<pair<int, int>, int> dp;
        function<int(int, int)> dfs = [&] (int i, int j) {
            if (i >= text1.size() or j >= text2.size()) {
                return 0;
            }

            if (dp.contains({i, j})) {
                return dp[{i, j}];
            }
            
            if (text1[i] == text2[j]) {
                return dp[{i, j}] = 1 + dfs(i + 1, j + 1);
            }

            return dp[{i, j}] = max(dfs(i + 1, j), dfs(i, j + 1));
        };

        return dfs(0, 0);
    }
};
