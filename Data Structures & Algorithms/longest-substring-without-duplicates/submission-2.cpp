class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") {
            return 0;
        }
        
        int l = 0, res = 1;
        unordered_set<char> charSet;
        for (int r = 0; r < s.size(); r++) {
            while (charSet.find(s[r]) != charSet.end()) {
                charSet.erase(s[l]);
                l++;
            }
            res = max(res, r - l + 1);
            charSet.insert(s[r]);
        }
        return res;
    }
};
