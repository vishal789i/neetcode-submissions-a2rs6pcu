class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, res = 0;
        vector<int> cnt(26);
        for (int r = 0; r < s.size(); ++r) {
            cnt[s[r] - 'A']++;
            while ((r - l + 1) - *max_element(cnt.begin(), cnt.end()) > k) {
                cnt[s[l] - 'A']--;
                l++;
            }

            // windowLen - maxF >= k
            res = max(res, r - l + 1);
        }

        return res;
    }
};
