class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        vector<int> s1Cnt(26, 0), s2Cnt(26, 0);
        for (int i = 0; i < s1.length(); ++i) {
            s1Cnt[s1[i] - 'a'] ++;
            s2Cnt[s2[i] - 'a'] ++;
        }

        int matches = 0;
        for (int i = 0; i < 26; ++i) {
            if (s1Cnt[i] == s2Cnt[i]) {
                matches ++;
            }
        }

        int l = 0;
        for (int r = s1.length(); r < s2.length(); ++r) {
            if (matches == 26) {
                return true;
            }

            int idx = s2[r] - 'a';
            s2Cnt[idx]++;
            if (s1Cnt[idx] == s2Cnt[idx]) {
                matches ++;
            } else if (s1Cnt[idx] + 1 == s2Cnt[idx]) {
                matches --;
            }

            idx = s2[l] - 'a';
            s2Cnt[idx]--;
            if (s1Cnt[idx] == s2Cnt[idx]) {
                matches ++;
            } else if (s1Cnt[idx] - 1 == s2Cnt[idx]) {
                matches --;
            }

            l ++;
        }

        return matches == 26;
    }
};
