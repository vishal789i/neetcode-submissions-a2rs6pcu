class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while (i < j) {
            while (not isalnum(s[i])) {
                i++;
            }

            while (not isalnum(s[j])) {
                j--;
            }

            if (i > j) break;

            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            
            i++;
            j--;
        }

        return true;
    }
};
