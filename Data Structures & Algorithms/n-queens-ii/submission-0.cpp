class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        set<int> colSet;
        set<int> posDiagSet;
        set<int> negDiagSet;
        vector<string> ans(n, string(n, '.'));
        function<void(int)> dfs = [&] (int r) {
            if (r == n) {
                res++;
                return;
            }

            for (int c = 0; c < n; ++c) {
                if (colSet.count(c) or posDiagSet.count(r + c) or negDiagSet.count(r - c) or ans[r][c] == 'Q') {
                    continue;
                }

                colSet.insert(c);
                posDiagSet.insert(r + c);
                negDiagSet.insert(r - c);
                ans[r][c] = 'Q';
                dfs(r + 1);
                colSet.erase(c);
                posDiagSet.erase(r + c);
                negDiagSet.erase(r - c);
                ans[r][c] = '.';
            }
        };
        
        dfs(0);
        return res;
    }
};
