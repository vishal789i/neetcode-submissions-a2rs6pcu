class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1Cnt(26), s2Cnt(26);
        for (auto ch : s1) {
            s1Cnt[ch - 'a']++;
        }

        int l = 0;
        for (int r = 0; r < s2.size(); ++r) {
            s2Cnt[s2[r] - 'a']++;
            if (r - l + 1 > s1.size()) {
                s2Cnt[s2[l] - 'a']--;
                l++;
            }

            if (s1Cnt == s2Cnt) {
                return true;
            }
        }

        return false;
    }
};
