class Solution {
public:
    int characterReplacement(string s, int k) {
        size_t maxLen = 0;
        for (int offset = 0; offset < s.size(); ++offset) {
            for (int length = 1; length <= s.size() - offset; ++length) {
                string subStr = s.substr(offset, length);
                map<char, int> char2Freq;
                for (auto ch : subStr) {
                    char2Freq[ch]++;
                }
                
                int maxFreq = 0;
                for (auto [ch, freq]: char2Freq) {
                    maxFreq = max(maxFreq, freq);
                }
                
                if (subStr.size() - maxFreq <= k) {
                    maxLen = max(maxLen, subStr.size());
                }
            }
        }

        return maxLen;
    }
};
