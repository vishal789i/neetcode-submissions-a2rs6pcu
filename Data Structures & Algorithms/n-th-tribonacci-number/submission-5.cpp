class Solution {
public:
    map<int, int> dp;
    int tribonacci(int n) {
        if (n <= 1) {
            return n;
        }

        if (n == 2) {
            return 1;
        }

        if (dp[n]) {
            return dp[n];
        }

        return dp[n] = tribonacci(n - 3) + tribonacci(n - 2) + tribonacci(n - 1);
    }
};