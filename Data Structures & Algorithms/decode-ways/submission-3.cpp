class Solution {
public:

    int numDecodings(string s) {
        function<int(int)> dfs = [&] (int i) {
            if (i == s.size()) {
                return 1;
            }

            if (s[i] == '0') {
                return 0;
            }
            
            int res = dfs(i + 1);
            if (s[i] == '1' or (s[i] == '2' and i + 1 < s.size() and s[i + 1] < '7')) {
                res += dfs(i + 2);
            }

            return res;
        };

        return dfs(0);
    }
};
