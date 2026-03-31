class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> col2CellSet;
        unordered_map<int, unordered_set<int>> row2CellSet;
        unordered_map<int, unordered_set<int>> box2CellSet;

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                int cell = board[i][j];
                if (cell == '.') continue;

                int boxHash = i/3 * 3 + j/3;

                if (col2CellSet[j].count(cell) || row2CellSet[i].count(cell) || box2CellSet[boxHash].count(cell)) {
                    return false;
                }
                col2CellSet[j].insert(cell);
                row2CellSet[i].insert(cell);
                box2CellSet[boxHash].insert(cell);
            }
        }
        return true;
    }
};
