class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        map<char, int> freqs;
        int l = 0, r = 0, res = 0;
        while (r < s.size()) {
            freqs[s[r]]++;
            while (freqs.size() > 2) {
                freqs[s[l]]--;
                if (freqs[s[l]] == 0) {
                    freqs.erase(s[l]);
                }

                l++;
            }

            res = max(res, r - l + 1);
            r++;
        }

        return res;
    }
};