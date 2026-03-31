class Solution {
public:
    bool validPalindrome(string s) {
        auto isPalindrome = [&] (int l, int r) {
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
            if (s[l] == s[r]) {
                l++;
                r--;
            } else {
                return isPalindrome(l + 1, r) or isPalindrome(l, r - 1);
            }
        }

        return true;
    }
};