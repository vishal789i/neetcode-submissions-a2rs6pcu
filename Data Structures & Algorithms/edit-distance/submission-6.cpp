class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector cur(m + 1, 0), prev(m + 1, 0);
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (i == 0) {
                    cur[j] = j;
                } else if (j == 0) {
                    cur[j] = i;
                } else {
                    if (s1[i - 1] == s2[j - 1]) {
                        cur[j] = prev[j - 1];
                    } else {
                        cur[j] = 1 + min({cur[j - 1], prev[j], prev[j - 1]});
                    }
                }
            }

            prev = cur;
        }

        return prev[m];
    }
};
