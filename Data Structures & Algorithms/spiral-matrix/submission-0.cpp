class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        int ROWS = m.size(), COLS = m[0].size();
        int l = 0, r = COLS, t = 0, b = ROWS;
        vector<int> res;
        while (l < r and t < b) {
            for (int i = l; i < r; ++i) {
                res.push_back(m[t][i]);
            }
            t++;

            for (int i = t; i < b; ++i) {
                res.push_back(m[i][r - 1]);
            }
            r--;

            if (l >= r or t >= b) {
                break;
            }

            for (int i = r - 1; i >= l; --i) {
                res.push_back(m[b - 1][i]);
            }
            b--;

            for (int i = b - 1; i >= t; --i) {
                res.push_back(m[i][l]);
            }
            l++;
        }

        return res;
    }
};
