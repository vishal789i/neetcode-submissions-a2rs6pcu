class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        map<int, int> dp;
        function<int(int)> dfs = [&] (int i) {
            if (i >= days.size()) {
                return 0;
            }

            if (dp.contains(i)) {
                return dp[i];
            }

            // chose 1 day pass
            int oneDayPassCost = costs[0] + dfs(i + 1);

            // chose 7 day pass
            int j = i;
            while (j < days.size() and days[j] < days[i] + 7) {
                j++;
            }

            int sevenDayPassCost = costs[1] + dfs(j);

            // chose 30 day pass
            j = i;
            while (j < days.size() and days[j] < days[i] + 30) {
                j++;
            }

            int thirtyDayPassCost = costs[2] + dfs(j);
            return dp[i] = min({oneDayPassCost, sevenDayPassCost, thirtyDayPassCost});
        };

        return dfs(0);
    }
};