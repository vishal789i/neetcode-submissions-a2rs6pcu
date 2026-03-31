class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, res = 0;
        vector<int> counts(26);
        while (r < s.size()) {
            counts[s[r] - 'A']++;
            while (r - l + 1 - *max_element(counts.begin(), counts.end()) > k) {
                counts[s[l] - 'A']--;
                l++;
            }

            res = max(res, r - l + 1);
            r++;
        }

        return res;
    }
};
