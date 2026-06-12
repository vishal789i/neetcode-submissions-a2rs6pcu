class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector dp(s1.size() + 1, vector(s2.size() + 1, vector(s3.size() + 1, -1)));
        for (int i = s1.size(); i >= 0; --i) {
            for (int j = s2.size(); j >= 0; --j) {
                for (int k = s3.size(); k >= 0; --k) {
                    if (i == s1.size() and j == s2.size() and k == s3.size()) {
                        dp[i][j][k] = 1;
                    } else {
                        bool res = false;
                        if (i < s1.size() and s1[i] == s3[k]) {
                            res |= dp[i + 1][j][k + 1];
                        }
                        
                        if (j < s2.size() and s2[j] == s3[k]) {
                            res |= dp[i][j + 1][k + 1];
                        }

                        dp[i][j][k] = res;
                    }
                }
            }
        }

        return dp[0][0][0];
    }
};
