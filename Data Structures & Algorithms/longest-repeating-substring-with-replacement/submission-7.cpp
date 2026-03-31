class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> ch2Cnt;
        int l = 0;
        int res = 0;
        for (int r = 0; r < s.size(); ++r) {
            ch2Cnt[s[r]]++;
            int maxCnt = 0;
            for (auto [ch, cnt] : ch2Cnt) {
                maxCnt = max(maxCnt, cnt);
            }

            int curLen = r - l + 1;
            if (curLen - maxCnt <= k) {
                res = max(res, curLen);
            } else {
                if (curLen - maxCnt > k) {
                    ch2Cnt[s[l]]--;
                    l++;
                }
            }
        }

        return res;
    }
};
