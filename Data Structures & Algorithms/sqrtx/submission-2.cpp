class Solution {
public:
    int mySqrt(int x) {
        int res = 0;
        for (int i = 1; i <= x; ++i) {
            if ((long long)i * i > x) {
                return res;
            }

            res = i;
        }

        return res;
    }
};