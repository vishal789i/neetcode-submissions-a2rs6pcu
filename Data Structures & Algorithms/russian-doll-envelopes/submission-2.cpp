class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [] (auto&& e1, auto&& e2) {
            return e1[0] == e2[0] ? e1[1] < e2[1] : e1[0] < e2[0];
        });

        int N = envelopes.size();
        vector<int> dp(N, 1);
        int res = 0;
        for (int i = N - 1; i >= 0; --i) {
            for (int j = i + 1; j < N; ++j) {
                if (envelopes[j][0] > envelopes[i][0] and envelopes[j][1] > envelopes[i][1]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }

            res = max(res, dp[i]);
        }
        
        return res;
    }
};