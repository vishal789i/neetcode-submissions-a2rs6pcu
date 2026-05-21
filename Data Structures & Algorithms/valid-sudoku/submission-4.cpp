class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        auto ROWS = board.size(), COLS = board[0].size();
        map<int, set<char>> row2NumSet, col2NumSet;
        map<pair<int, int>, set<char>> grid2NumSet;
        for (auto r = 0; r < ROWS; ++r) {
            for (auto c = 0; c < COLS; ++c) {
                auto num = board[r][c];
                if (num == '.') {
                    continue;
                }

                if (row2NumSet[r].count(num) or col2NumSet[c].count(num) or grid2NumSet[{r/3, c/3}].count(num)) {
                    return false;
                }

                row2NumSet[r].insert(num);
                col2NumSet[c].insert(num);
                grid2NumSet[{r/3, c/3}].insert(num);
            }
        }

        return true;
    }
};
