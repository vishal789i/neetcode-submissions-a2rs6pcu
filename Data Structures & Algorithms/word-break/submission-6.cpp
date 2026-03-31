class Solution {
public:
    bool dfs(string& s, unordered_set<string>& dict, int idx, vector<int>& dp) {
        if (idx >= s.size()) {
            return true;
        }

        if (dp[idx] != -1) {
            return dp[idx];
        }

        string curS = "";
        for (int i = idx; i < s.size(); ++i) {
            curS += s[i];
            if (dict.count(curS)) {
                if (dfs(s, dict, i + 1, dp)) {
                    dp[idx] = true;
                    return true;
                }
            }
        }

        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size() + 1, -1);
        return dfs(s, dict, 0, dp);
    }
};
