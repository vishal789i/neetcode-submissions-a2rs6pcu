class Solution {
public:
    map<int, int> dp;
    int climbStairs(int n) {
        if (n == 0) {
            return 1;
        }

        if (n < 0) {
            return 0;
        }

        if (dp.contains(n)) {
            return dp[n];
        }

        return dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};
