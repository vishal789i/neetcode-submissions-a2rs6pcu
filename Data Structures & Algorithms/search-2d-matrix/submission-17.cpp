class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        int low = 0, high = (ROWS * COLS) - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int midR = mid / COLS, midC = mid % COLS;
            if (matrix[midR][midC] == target) {
                return true;
            } else if (target < matrix[midR][midC]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return false;
    }
};
