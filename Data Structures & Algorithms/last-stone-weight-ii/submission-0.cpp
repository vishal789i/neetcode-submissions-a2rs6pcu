class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int total = accumulate(stones.begin(), stones.end(), 0);
        int targetSum = ceil(total / 2.0);
        map<pair<int, int>, int> dp;
        function<int(int, int)> dfs = [&] (int i, int curSum) {
            if (curSum >= targetSum or i == stones.size()) {
                return abs(curSum - (total - curSum));
            }

            if (dp.contains({i, curSum})) {
                return dp[{i, curSum}];
            }

            return dp[{i, curSum}] = min(dfs(i + 1, curSum + stones[i]), dfs(i + 1, curSum));
        };

        return dfs(0, 0);
    }
};