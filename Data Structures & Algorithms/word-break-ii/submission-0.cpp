class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<string> res;
        function<void(int, string)> dfs = [&] (int i, string op) {
            if (i == s.size()) {
                op.erase(0, 1);
                res.push_back(op);
                return;
            }

            string tmp = "";
            for (int j = i; j < s.size(); ++j) {
                tmp += s[j];
                if (dict.contains(tmp)) {
                    dfs(j + 1, op + " " + tmp);
                }
            }
        };

        dfs(0, "");
        return res;
    }
};