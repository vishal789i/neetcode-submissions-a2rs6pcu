class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") {
            return 0;
        }

        int i = 0, j = 0;
        unordered_set<char> ss;
        int maxSize = INT_MIN;
        while (j < s.size()) {
            while (ss.find(s[j]) != ss.end()) {
                ss.erase(s[i]);
                i++;
            }
            maxSize = max(maxSize, j - i + 1);
            ss.insert(s[j]);
            j++;
        }
        return maxSize;
    }
};
