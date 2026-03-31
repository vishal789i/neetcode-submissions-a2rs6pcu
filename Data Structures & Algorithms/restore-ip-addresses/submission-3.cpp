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
            if (j - i > 0 and s[i] == '0') { // only zero with len 1 allowed
                continue;
            }

            num += s[j];
            if (stoi(num) <= 255) {
                dfs(s, j + 1, dots + 1, op + num + ".");
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 12) {
            return res;
        }

        dfs(s, 0, 0, "");
        return res;
    }
};