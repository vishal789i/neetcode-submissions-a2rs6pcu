class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector prev(m + 1, 0), cur(n + 1, 0);
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i == 0 or j == 0) {
                    cur[j] = 0;
                    continue;
                }

                if (text1[i - 1] == text2[j - 1]) {
                    cur[j] = 1 + prev[j - 1];
                } else {
                    cur[j] = max(prev[j], cur[j - 1]);
                }
            }

            prev = cur;
        }

        return prev[n];
    }
};
