class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            vector<int> freqs(26);
            int maxFreq = 0;
            for (int j = i; j < s.size(); ++j) {
                freqs[s[j] - 'A']++;
                maxFreq = max(maxFreq, freqs[s[j] - 'A']);
                if (j - i + 1 - maxFreq <= k) {
                    res = max(res, j - i + 1);
                }
            }
        }

        return res;
    }
};
