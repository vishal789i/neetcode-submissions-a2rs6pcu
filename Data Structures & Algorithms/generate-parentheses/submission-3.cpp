class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string op;
        vector<string> res;
        function<void(int, int)> f = [&] (int open, int close) {
            if (open == n and close == n) {
                res.push_back(op);
                return;
            }

            if (open < n) {
                op.push_back('(');
                f(open + 1, close);
                op.pop_back();
            }

            if (close < open) {
                op.push_back(')');
                f(open, close + 1);
                op.pop_back();
            }
        };

        f(0, 0);
        return res;
    }
};
