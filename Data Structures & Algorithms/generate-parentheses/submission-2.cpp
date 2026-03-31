class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string op;
        function<void(int, int)> dfs = [&] (int open, int close) {
            if (open == 0 and close == 0) {
                res.push_back(op);
                return;
            }

            if (open > 0) {
                op.push_back('(');
                dfs(open - 1, close);
                op.pop_back();
            }

            if (close > open) {
                op.push_back(')');
                dfs(open, close - 1);
                op.pop_back();
            }
        };
        
        dfs(n, n);
        return res;
    }
};
