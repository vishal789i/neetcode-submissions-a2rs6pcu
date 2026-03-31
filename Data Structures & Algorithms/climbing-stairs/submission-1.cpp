class Solution {
public:
    int climbStairs(int n) {
        static vector<int> dp(31, 0);
        if (n <= 1) {
            return 1;
        }

        if (dp[n]) {
            return dp[n];
        }

        return climbStairs(n-1) + climbStairs(n-2);
    }
};
