class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        auto ROWS = triangle.size();
        vector cur(ROWS, -1), next(ROWS, -1);
        for (int r = ROWS - 1; r >= 0; --r) {
            for (int c = triangle[r].size() - 1; c >= 0; --c) {
                if (r == ROWS - 1) {
                    if (c < triangle[r].size()) {
                        cur[c] = triangle[r][c];
                    } else {
                        cur[c] = INT_MIN;
                    }
                } else {
                    cur[c] = triangle[r][c] + min(next[c], next[c + 1]);
                }
            }

            next = cur;
        }

        return next[0];
    }
};