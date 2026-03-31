class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        map<tuple<bool, int, int>, int> dp;
        function<int(bool, int, int)> dfs = [&] (bool isAlice, int i, int M) {
            if (i == n) {
                return 0;
            }

            if (dp.contains({isAlice, i, M})) {
                return dp[{isAlice, i, M}];
            }

            int res = isAlice ? INT_MIN : INT_MAX;
            int stones = 0;
            for (int X = 1; X <= min(2 * M, n - i); ++X) {
                stones += piles[i + X - 1];
                if (isAlice) {
                    res = max(res, stones + dfs(false, i + X, max(M, X)));
                } else {
                    res = min(res, dfs(true, i + X, max(M, X)));
                }
            }

            return dp[{isAlice, i, M}] = res;
        };

        return dfs(true, 0, 1);
    }
};