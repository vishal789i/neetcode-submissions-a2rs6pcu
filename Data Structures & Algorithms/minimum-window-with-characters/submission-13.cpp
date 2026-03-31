class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        map<int, int> countT, window;
        for (auto ch : t) {
            countT[ch]++;
        }

        int have = 0, need = countT.size();
        int l = 0, r = 0;
        int resStart = 0, resLen = INT_MAX;
        for (int r = 0; r < s.size(); ++r) {
            window[s[r]]++;

            if (window[s[r]] == countT[s[r]]) {
                have++;
            }

            while (have == need) {
                if ((r - l + 1) < resLen) {
                    resLen = (r - l + 1);
                    resStart = l;
                }

                window[s[l]]--;
                if (window[s[l]] < countT[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(resStart, resLen);
    }
};
