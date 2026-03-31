class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, res = 0;
        vector<int> freqs(26);
        while (r < s.size()) {
            freqs[s[r] - 'A']++;
            while (r - l + 1 - *max_element(freqs.begin(), freqs.end()) > k) {
                freqs[s[l] - 'A']--;
                l++;
            }

            // now wlen - maxf == k
            res = max(res, r - l + 1);
            r++;
        }

        return res;
    }
};
