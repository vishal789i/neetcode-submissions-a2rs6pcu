class Solution {
public:
    int numDistinct(string s, string t) {
        int cnt = 0;
        function<void(int, string&)> dfs = [&] (int idx, string& op) {
            if (idx == s.size()) {
                if (op == t) {
                    cnt++;
                }
                return;
            }
            
            op.push_back(s[idx]);
            dfs(idx + 1, op);
            op.pop_back();

            dfs(idx + 1, op);
        };

        string op;
        dfs(0, op);
        return cnt;
    }
};
