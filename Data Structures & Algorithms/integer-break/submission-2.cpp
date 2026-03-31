class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }

        map<int, int> dp;
        function<int(int)> dfs = [&] (int num) {
            if (num <= 3) {
                return num;
            }

            if (dp[num]) {
                return dp[num];
            }
            
            int res = num;
            for (int k = 2; k <= num; k++) {
                res = max(res, k * dfs(num - k));
            }

            return dp[num] = res;
        };

        return dfs(n);
    }
};