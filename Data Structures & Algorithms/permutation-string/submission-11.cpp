class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        vector<int> s1Count(26, 0), s2Count(26, 0);
        for (int i = 0; i < s1.size(); ++i) {
            s1Count[s1[i] - 'a'] ++;
            s2Count[s2[i] - 'a'] ++;
        }

        int matches = 0;
        for (int i = 0; i < 26; ++i) {
            matches += (s1Count[i] == s2Count[i]) ? 1 : 0;
        }

        int l = 0; // r window already processed;
        for (int r = s1.size(); r < s2.size(); ++r) {
            if (matches == 26) return true; 

            int idx = s2[r] - 'a';
            s2Count[idx] ++;
            if (s1Count[idx] == s2Count[idx]) {
                matches ++;
            } else if (s1Count[idx] + 1 == s2Count[idx]) {
                matches --;
            }

            idx = s2[l] - 'a';
            s2Count[idx] --;
            l++;
            if (s1Count[idx] == s2Count[idx]) {
                matches ++;
            } else if (s1Count[idx] - 1 == s2Count[idx]) {
                matches --;
            }
        }

        return matches == 26;
    }
};
