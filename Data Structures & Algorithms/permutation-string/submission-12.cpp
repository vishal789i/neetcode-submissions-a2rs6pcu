class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1Freqs(26), s2Freqs(26);
        for (auto ch : s1) {
            s1Freqs[ch - 'a']++;
        }

        auto validLen = s1.size();
        int l = 0, r = 0;
        while (r < s2.size()) {
            s2Freqs[s2[r] - 'a']++;
            while (r - l + 1 > validLen) {
                s2Freqs[s2[l] - 'a']--;
                l++;
            }

            if (s1Freqs == s2Freqs) {
                return true;
            }

            r++;
        }

        return false;
    }
};