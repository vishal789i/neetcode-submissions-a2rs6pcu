class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int l = 0, r = 0, maxLen = 0;
        set<char> charSet;
        while (r < str.size()) {
            while (charSet.count(str[r])) {
                charSet.erase(str[l]);
                l++;
            }
            charSet.insert(str[r]);
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};
