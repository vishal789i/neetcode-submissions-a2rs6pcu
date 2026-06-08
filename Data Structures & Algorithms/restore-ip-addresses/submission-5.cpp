class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        function<void(int, string, int)> bt = [&] (int i, string op, int dots) {
            if (i == s.size() and dots == 4) {
                op.pop_back();
                res.push_back(op);
                return;
            }
            
            string tmp;
            for (int j = i; j < min((int)s.size(), i + 3); ++j) {
                if (j > i and s[i] == '0') {
                    continue;
                }
                
                tmp += s[j];
                if (stoi(tmp) <= 255) {
                    bt(j + 1, op + tmp + '.', dots + 1);
                }
            }
        };

        bt(0, "", 0);
        return res;
    }
};