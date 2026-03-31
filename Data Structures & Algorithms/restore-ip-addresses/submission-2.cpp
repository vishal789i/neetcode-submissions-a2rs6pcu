class Solution {
public:
    vector<string> res;
    void dfs(string& s, int i, int dots, string op) {
        if (i == s.size() and dots == 4) {
            op.pop_back(); // remove last dot
            res.push_back(op);
            return;
        }

        if (dots > 4) {
            return;
        }

        string num;
        for (int j = i; j < i + 3 and j < s.size(); ++j) {
            if (i != j and s[i] == '0') {
                continue;
            }

            num += s[j];
            if (stoi(num) <= 255) {
                dfs(s, j + 1, dots + 1, op + num + ".");
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0, 0, "");
        return res;
    }
};