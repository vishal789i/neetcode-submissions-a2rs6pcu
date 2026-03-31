class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector cur(m + 1, 0), prev(m + 1, 0);
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (j == 0) {
                    cur[j] = 1;
                } else if (i == 0) {
                    cur[j] = 0;
                } else {
                    if (s[i - 1] == t[j - 1]) {
                        cur[j] = prev[j - 1] + prev[j];
                    } else {
                        cur[j] = prev[j];
                    }
                }
            }

            prev = cur;
        }
        
        return prev[m];
    }
};
