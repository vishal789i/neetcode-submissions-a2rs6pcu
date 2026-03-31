class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        set<string> dict(dictionary.begin(), dictionary.end());
        map<int, int> dp;
        function<int(int)> dfs = [&] (int i) {
            if (i == s.size()) {
                return 0;
            }

            if (dp.contains(i)) {
                return dp.at(i);
            }

            int notPick = 1 + dfs(i + 1);
            string temp = "";
            int pick = INT_MAX;
            for (int j = i; j < s.size(); ++j) {
                temp += s[j];
                if (dict.contains(temp)) {
                    pick = min(pick, dfs(j + 1));
                }
            }

            return dp[i] = min(pick, notPick);
        };

        return dfs(0);
    }
};