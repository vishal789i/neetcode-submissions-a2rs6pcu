class Solution {
public:
    bool checkValidString(string s) {
        vector dp(s.size() + 1, vector(s.size() + 1, -1));
        function<bool(int, int)> f = [&] (int i, int cnt) -> bool {
            if (cnt < 0) {
                return false;
            }

            if (i == s.size()) {
                return cnt == 0;
            }

            if (dp[i][cnt] != -1) {
                return dp[i][cnt];
            }

            if (s[i] == '(') {
                return dp[i][cnt] = f(i + 1, cnt + 1);
            }

            if (s[i] == ')') {
                return dp[i][cnt] = f(i + 1, cnt - 1);
            }

            return dp[i][cnt] = f(i + 1, cnt) or f(i + 1, cnt + 1) or f(i + 1, cnt - 1);
        };

        return f(0, 0);
    }
};
