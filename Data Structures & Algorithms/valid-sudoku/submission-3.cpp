class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        auto ROWS = board.size(), COLS = board[0].size();
        map<int, set<char>> row2NumSet, col2NumSet, grid2NumSet;
        for (auto r = 0; r < ROWS; ++r) {
            for (auto c = 0; c < COLS; ++c) {
                auto num = board[r][c];
                if (num == '.') {
                    continue;
                }

                auto hash = (r/3 * 3 + c/3);
                if (row2NumSet[r].count(num) or col2NumSet[c].count(num) or grid2NumSet[hash].count(num)) {
                    return false;
                }

                row2NumSet[r].insert(num);
                col2NumSet[c].insert(num);
                grid2NumSet[hash].insert(num);
            }
        }

        return true;
    }
};
