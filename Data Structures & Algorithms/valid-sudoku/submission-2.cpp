class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int, set<int>> row2CellSet;
        map<int, set<int>> col2CellSet;
        map<int, set<int>> box2CellSet;
        for (int r = 0; r < board.size(); ++r) {
            for (int c = 0; c < board[r].size(); ++c) {
                auto cell = board[r][c];
                if (cell == '.') continue;

                int boxHash = r/3 * 3 + c/3;
                if (row2CellSet[r].count(cell) or col2CellSet[c].count(cell) or box2CellSet[boxHash].count(cell)) {
                    return false;
                }

                row2CellSet[r].insert(cell);
                col2CellSet[c].insert(cell);
                box2CellSet[boxHash].insert(cell);
            }
        }
        
        return true;
    }
};
