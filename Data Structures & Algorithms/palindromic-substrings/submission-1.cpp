class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        function<bool(int, int)> isPal = [&](int i, int j) {
            if (i >= j) {
                return true;
            }
            
            if (s[i] != s[j]) {
                return false;
            }
            
            return isPal(i + 1, j - 1);
        };
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPal(i, j)) count++;
            }
        }
        
        return count;
    }
};