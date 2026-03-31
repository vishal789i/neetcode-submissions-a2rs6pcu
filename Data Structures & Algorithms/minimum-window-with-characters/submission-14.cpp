class Solution {
public:
    string minWindow(string s, string t) {
        map<int, int> tCounts, windowCounts;
        for (auto ch : t) {
            tCounts[ch]++;
        }
        
        int need = tCounts.size(), have = 0;
        int resStart = 0;
        int resLen = INT_MAX;
        int l = 0;
        for (int r = 0; r < s.size(); ++r) {
            windowCounts[s[r]]++;
            if (windowCounts[s[r]] == tCounts[s[r]]) {
                have++;
            }

            while (have == need) {
                if (r - l + 1 < resLen) {
                    resLen = r - l + 1;
                    resStart = l;
                }

                windowCounts[s[l]]--;
                if (windowCounts[s[l]] < tCounts[s[l]]) {
                    have--;
                }

                l++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(resStart, resLen);
    }
};
