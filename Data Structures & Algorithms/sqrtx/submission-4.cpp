class Solution {
public:
    int mySqrt(int x) {
        int l = 1, r = x, res = 0;
        while (l <= r) {
            int m = (l + r) / 2;
            if ((long long)m * m <= x) {
                res = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return res;
    }
};