class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int totalLen = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        int side = totalLen / 4;
        vector<int> sides(4);
        sort(matchsticks.begin(), matchsticks.end(), greater<>());
        function<bool(int)> dfs = [&] (int i) {
            if (i == matchsticks.size()) {
                return sides[0] == side and sides[1] == side and sides[2] == side and sides[3] == side;
            }

            for (int j = 0; j < 4; ++j) {
                if (sides[j] + matchsticks[i] <= side) {
                    sides[j] += matchsticks[i];
                    if (dfs(i + 1)) {
                        return true;
                    }

                    sides[j] -= matchsticks[i];
                }

                if (sides[j] == 0) {
                    return false;
                }
            }

            return false;
        };

        return dfs(0);
    }
};