class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [] (auto&& e1, auto&& e2) {
            return e1[0] == e2[0] ? e1[1] < e2[1] : e1[0] < e2[0];
        });

        int N = envelopes.size();
        function<int(int)> dfs = [&] (int i) {
            if (i >= N) {
                return 0;
            }

            int res = 1;
            for (int j = i + 1; j < N; ++j) {
                if (envelopes[j][0] > envelopes[i][0] and envelopes[j][1] > envelopes[i][1]) {
                    res = max(res, 1 + dfs(j));
                }
            }

            return res;
        };
        

        int res = 1;
        for (int i = 0; i < N; ++i) {
            res = max(res, dfs(i));
        }
        
        return res;
    }
};