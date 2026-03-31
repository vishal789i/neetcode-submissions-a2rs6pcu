class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int l = 0, r = 0, maxlen = 0;
        set<char> s;
        while (r < str.size()) {
            while (s.count(str[r]) != 0) {
                s.erase(str[l]);
                l++;
            }
            maxlen = max(maxlen, r - l + 1);
            s.insert(str[r++]);
        }
        return maxlen;
    }
};
