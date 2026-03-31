class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1Counts(26), s2Counts(26);
        for (auto c : s1) {
            s1Counts[c - 'a']++;
        }

        int l = 0;
        for (int r = 0; r < s2.size(); ++r) {
            s2Counts[s2[r] - 'a']++;
            if (r - l + 1 > s1.size()) {
                s2Counts[s2[l] - 'a']--;
                l++;
            }

            if (s1Counts == s2Counts) {
                return true;
            }
        }

        return false;
    }
};
