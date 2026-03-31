class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        vector<int> sides(4);
        auto totalLen = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        auto sideLen = totalLen / 4;
        sort(matchsticks.rbegin(), matchsticks.rend());
        function<bool(int)> dfs = [&] (int i) {
            if (i == matchsticks.size()) {
                return sides[0] == sideLen && sides[1] == sideLen && sides[2] == sideLen && sides[3] == sideLen;
            }

            for (int j = 0; j < 4; ++j) {
                if (sides[j] + matchsticks[i] <= sideLen) {
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