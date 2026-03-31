class Solution {
public:
    int dfs(string& s, int i) {
        if (i == s.size()) return 1;

        if (s[i] == '0') return 0;
        
        int res = dfs(s, i + 1);
        
        if (i + 1 < s.size()) {
            if (s[i] == '1' or (s[i] == '2' and s[i + 1] < '7')) {
                res += dfs(s, i + 2);
            }
        }

        return res;
    }

    int numDecodings(string s) {
        return dfs(s, 0);    
    }
};
