class Solution {
public:
    int dfs(string& s, int i, vector<int>& dp) {
        if (i == s.size()) return 1;

        if (dp[i] != -1) {
            return dp[i];
        }

        if (s[i] == '0') return 0;
        
        int res = dfs(s, i + 1, dp);

        if (i + 1 < s.size()) {
            if (s[i] == '1' or (s[i] == '2' and s[i + 1] < '7')) {
                res += dfs(s, i + 2, dp);
            }
        }

        return dp[i] = res;
    }

    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return dfs(s, 0, dp);    
    }
};
