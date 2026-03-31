class NumMatrix {
    vector<vector<int>> m_SumMatrix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        auto ROWS = matrix.size(), COLS = matrix[0].size();
        m_SumMatrix.assign(ROWS + 1, vector<int>(COLS + 1, 0));
        for (int r = 0; r < ROWS; ++r) {
            int prefixSum = 0;
            for (int c = 0; c < COLS; ++c) {
                prefixSum += matrix[r][c];
                auto aboveSum = m_SumMatrix[r][c + 1];
                m_SumMatrix[r + 1][c + 1] = prefixSum + aboveSum;
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        r1++; c1++; r2++; c2++; // +1 for dummy r, c
        auto bottomRightSum = m_SumMatrix[r2][c2];
        auto topRightSum = m_SumMatrix[r1 - 1][c2];
        auto bottomLeftSum = m_SumMatrix[r2][c1 - 1];
        auto topLeftSum = m_SumMatrix[r1 - 1][c1 - 1];
        return bottomRightSum - topRightSum - bottomLeftSum + topLeftSum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */