class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0;
        for (int i = 0; i < s.size(); ++i) {
            unordered_map<char, int> char2Freq;
            int maxFreq = 0;
            for (int j = i; j < s.size(); ++j) {
                char2Freq[s[j]]++;
                maxFreq = max(maxFreq, char2Freq[s[j]]);
                int windowLen = j - i + 1;
                if (windowLen - maxFreq <= k) {
                    maxLen = max(maxLen, windowLen);
                } else {
                    break;
                }
            }
        }

        return maxLen;
    }
};
