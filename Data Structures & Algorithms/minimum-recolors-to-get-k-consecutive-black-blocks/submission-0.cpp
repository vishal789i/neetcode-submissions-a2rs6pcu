class Solution {
public:
    int minimumRecolors(string s, int k) {
        int WCount = 0, BCount = 0;
        int l = 0, r = 0, res = k;
        while (r < s.size()) {
            if (s[r] == 'W') {
                WCount++;
            } else {
                BCount++;
            }

            if (r - l + 1 == k) {
                res = min(res, WCount);
                if (s[l] == 'W') {
                    WCount--;
                } else {
                    BCount--;
                }

                l++;
            }

            r++;
        }

        return res;
    }
};