class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
                continue;
            }

            // delete i
            int i1 = i + 1, j1 = j;
            bool isPal = true;
            while (i1 < j1) {
                if (s[i1] != s[j1]) {
                    isPal = false;
                    break;
                }

                i1++;
                j1--;
            }

            if (isPal)
                return true;

            // delete j
            int i2 = i, j2 = j - 1;
            while (i2 < j2) {
                if (s[i2] != s[j2])
                    return false;

                i2++;
                j2--;
            }

            return true;
        }

        return true;
    }
};