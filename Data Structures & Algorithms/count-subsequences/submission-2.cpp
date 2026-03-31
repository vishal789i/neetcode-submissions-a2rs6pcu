class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector dp(n + 1, vector(m + 1, -1));
        function<int(int, int)> f = [&] (int i, int j) {
            if (j == 0) {
                return 1;
            } else if (i == 0) {
                return 0;
            }

            if (dp[i][j] != -1) {
                return dp[i][j];
            }

            if (s[i - 1] == t[j - 1]) {
                return dp[i][j] = f(i - 1, j - 1) + f(i - 1, j);
            }

            return dp[i][j] = f(i - 1, j);
        };

        return f(n, m);
    }
};
