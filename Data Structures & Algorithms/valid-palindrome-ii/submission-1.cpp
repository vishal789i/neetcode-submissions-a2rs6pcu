class Solution {
public:
    bool validPalindrome(string s) {
        auto isPal = [&s] (int l, int r) {
            while (l < r) {
                if (s[l] != s[r]) {
                    return false;
                }
                l++;
                r--;
            }
            
            return true;
        };

        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                return isPal(l + 1, r) or isPal(l, r - 1);
            }

            l++;
            r--;
        }

        return true;
    }
};