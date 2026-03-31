class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int nR = matrix.size() - 1, nC = matrix[0].size() - 1;
        int rowL = 0, rowR = matrix.size() - 1, colL = 0, colR = matrix[0].size() - 1;
        while (rowL <= rowR) {
            int rowMid = (rowL + rowR)/2;
            if (target > matrix[rowMid][nC]) {
                rowL = rowMid + 1;
            } else if (target < matrix[rowMid][0]) {
                rowR = rowMid - 1;
            } else {
                break;
            }
        }

        if (rowL > rowR) {
            return false;
        }
        
        int rowMid = (rowL + rowR)/2;
        while (colL <= colR) {
            int colMid = (colL + colR)/2;
            if (target < matrix[rowMid][colMid]) {
                colR = colMid - 1;
            } else if (target > matrix[rowMid][colMid]) {
                colL = colMid + 1;
            } else {
                return true;
            }
        }

        return false;
    }
};
