class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0, l = 0;
        vector<int> freqs(26);
        for (int r = 0; r < s.size(); ++r) {
            freqs[s[r] - 'A']++;
            auto maxFreq = *max_element(freqs.begin(), freqs.end());
            while (r - l + 1 - maxFreq > k) {
                freqs[s[l] - 'A']--;
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};
