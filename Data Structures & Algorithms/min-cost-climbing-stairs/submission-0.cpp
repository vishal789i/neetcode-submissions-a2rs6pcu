class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int minn = INT_MAX;
        function<int(int)> dfs = [&] (int i) {
            if (i >= n) {
                return 0;
            }

            return cost[i] + min(dfs(i + 1), dfs(i + 2));
        };

        return min(dfs(0), dfs(1));
    }
};
