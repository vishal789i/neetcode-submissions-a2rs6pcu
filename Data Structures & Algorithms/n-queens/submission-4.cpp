class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        set<int> colSet, posDiagSet, negDiagSet;
        vector<string> op(n, string(n, '.'));
        function<void(int)> dfs = [&] (int r) {
            if (r == n) {
                res.push_back(op);
                return;
            }

            for (int c = 0; c < n; ++c) {
                if (colSet.contains(c) or posDiagSet.contains(r + c) or negDiagSet.contains(r - c) or op[r][c] == 'Q') {
                    continue;
                }

                colSet.insert(c);
                posDiagSet.insert(r + c);
                negDiagSet.insert(r - c);
                op[r][c] = 'Q';
                dfs(r + 1);
                op[r][c] = '.';
                negDiagSet.erase(r - c);
                posDiagSet.erase(r + c);
                colSet.erase(c);
            }
        };

        dfs(0);
        return res;
    }
};
