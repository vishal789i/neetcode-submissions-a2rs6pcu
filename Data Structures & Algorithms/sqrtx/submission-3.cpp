class Solution {
public:
    int mySqrt(int x) {
        int res = 0;
        int l = 1, r = x;
        while (l <= r) {
            int m = l + (r - l)/2;
            if ((long long)m * m > x) {
                r = m - 1;
            } else {
                res = m;
                l = m + 1;
            }
        }
        
        return res;
    }
};