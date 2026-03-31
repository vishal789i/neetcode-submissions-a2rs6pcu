class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string res = "";
        int resLen = 0;
        for (int i = 0; i < n; ++i) {
            int l = i, r = i;
            while (l >= 0 and r < n and s[l] == s[r]) {
                if (r - l + 1 > resLen) {
                    resLen = r - l + 1;
                    res = s.substr(l, resLen);
                }
                l--;
                r++;
            }

            l = i, r = i + 1;
            while (l >= 0 and r < n and s[l] == s[r]) {
                if (r - l + 1 > resLen) {
                    resLen = r - l + 1;
                    res = s.substr(l, resLen);
                }
                l--;
                r++;
            }
        }

        return res;
    }
};
