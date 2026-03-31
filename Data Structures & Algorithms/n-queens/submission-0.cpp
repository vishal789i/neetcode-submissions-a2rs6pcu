class Solution {
public:
    set<int> col;
    set<int> posDiag;
    set<int> negDiag;
    vector<vector<string>> res;
    
    void solve(vector<vector<char>>& board, int r, int n) {
        if (r == n) {
            vector<string> ans;
            for (int i = 0; i < n; ++i) {
                string temp = "";
                for (int j = 0; j < n; ++j) {
                    temp += board[i][j];
                }
                ans.push_back(temp);
            }
            res.push_back(ans);
            return;
        }

        for (int c = 0; c < n; ++c) {
            if (col.count(c) or posDiag.count(r-c) or negDiag.count(r+c) or board[r][c] == 'Q')
                continue;
            
            col.insert(c);
            posDiag.insert(r-c);
            negDiag.insert(r+c);
            board[r][c] = 'Q';
            
            solve(board, r+1, n);

            col.erase(c);
            posDiag.erase(r-c);
            negDiag.erase(r+c);
            board[r][c] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        solve(board, 0, n);
        return res;
    }
};
