class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        set<pair<char, char>> pathSet;
        int n = board.size();
        int m = board[0].size();

        function<bool(int, int, int)> solve = [&] (int r, int c, int i) {
            if (i == word.size()) {
                return true;
            }

            if (r < 0 or 
                c < 0 or 
                r > n-1 or 
                c > m-1 or 
                pathSet.count({r, c}) or 
                word[i] != board[r][c]) {
                return false;
            }

            pathSet.insert({r, c});
            bool res = (solve(r-1, c, i+1) or 
                        solve(r, c+1, i+1) or 
                        solve(r+1, c, i+1) or 
                        solve(r, c-1, i+1));
            pathSet.erase({r, c});
            return res;
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (solve(i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};
