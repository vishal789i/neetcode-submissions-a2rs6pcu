class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int nC = matrix[0].size();
        int nR = matrix.size();
        int rowLow = 0, rowHigh = nR - 1;
        while (rowLow <= rowHigh) {
            int rowMid = rowLow + (rowHigh - rowLow) / 2;
            if (target < matrix[rowMid][0]) {
                rowHigh = rowMid - 1;
            } else if (target > matrix[rowMid][nC-1]) {
                rowLow = rowMid + 1;
            } else {
                break;
            }
        }

        if (rowLow > rowHigh) {
            return false;
        }

        int rowMid = rowLow + (rowHigh - rowLow) / 2;
        int colLow = 0, colHigh = nC - 1;
        while (colLow <= colHigh) {
            int colMid = colLow + (colHigh - colLow) / 2;
            if (target < matrix[rowMid][colMid]) {
                colHigh = colMid - 1;
            } else if (target > matrix[rowMid][colMid]) {
                colLow = colMid + 1;
            } else {
                return true;
            }
        }
        
        return false;
    }
};
