class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> counts(n * n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                counts[grid[i][j] - 1]++;
            }
        }

        vector<int> res(2);
        for (int i = 0; i < counts.size(); ++i) {
            if (counts[i] == 0) {
                res[1] = i + 1;
            } else if (counts[i] == 2) {
                res[0] = i + 1;
            }
        }

        return res;
    }
};