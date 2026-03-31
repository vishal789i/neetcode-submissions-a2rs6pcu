class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxLen = 0, maxFreq = 0;
        unordered_map<char, int> char2Freq;
        while (r < s.size()) {
            char2Freq[s[r]]++;
            maxFreq = max(maxFreq, char2Freq[s[r]]);
            while (r - l + 1 - maxFreq > k) {
                char2Freq[s[l]]--;
                maxFreq = max(maxFreq, char2Freq[s[l]]);
                l++;
            }

            if (r - l + 1 - maxFreq <= k) {
                maxLen = max(maxLen, r - l + 1);
            }
            
            r++;
        }

        return maxLen;
    }
};
