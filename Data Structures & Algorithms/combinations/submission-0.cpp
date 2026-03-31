class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> ip;
        for (int i = 1; i <= n; ++i) {
            ip.push_back(i);
        }

        vector<vector<int>> res;
        vector<int> op;
        function<void(int)> dfs = [&] (int i) {
            if (op.size() == k) {
                res.push_back(op);
                return;
            }

            if (i == ip.size()) {
                return;
            }

            dfs(i + 1);
            op.push_back(ip[i]);
            dfs(i + 1);
            op.pop_back();
        };

        dfs(0);
        return res;
    }
};