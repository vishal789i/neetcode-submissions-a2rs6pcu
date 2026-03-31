class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }

        map<tuple<int, int, int>, bool> dp;
        function<bool(int, int, int)> dfs = [&] (int i, int j, int k) {
            if (i == s1.size() and j == s2.size() and k == s3.size()) {
                return true;
            }

            if (dp.contains({i, j, k})) {
                return dp[{i, j, k}];
            }

            bool res = false;
            if (i < s1.size() and s1[i] == s3[k]) {
                res = res or dfs(i + 1, j, k + 1);
            }

            if (j < s2.size() and s2[j] == s3[k]) {
                res = res or dfs(i, j + 1, k + 1);
            }

            return dp[{i, j, k}] = res;
        };

        return dfs(0, 0, 0);
    }
};
