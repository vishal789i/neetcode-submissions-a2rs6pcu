class Solution {
public:
    string minWindow(string s, string t) {
        if (t == "") {
            return "";
        }

        int minSubStrLen = INT_MAX;
        int minSubStrStartPos = 0;

        std::vector<int> tCount(255), windowCount(255);
        
        for (char tCh : t) {
            tCount[tCh] += 1;
        }

        int have = 0, need = 0;

        for (int count : tCount) {
            if (count > 0) {
                need += 1;
            }
        }

        int l = 0, r = 0;
        
        while (r < s.size()) {
            windowCount[s[r]] += 1;

            if (tCount[s[r]] > 0 and tCount[s[r]] == windowCount[s[r]]) {
                have += 1;
            }

            while (have == need) {
                if (r - l + 1 < minSubStrLen) {
                    minSubStrLen = r - l + 1;
                    minSubStrStartPos = l;
                }

                windowCount[s[l]] -= 1;
                
                if (tCount[s[l]] > 0 and windowCount[s[l]] < tCount[s[l]]) {
                    have -= 1;
                }

                l += 1;
            }

            r += 1;
        }

        if (minSubStrLen != INT_MAX) {
            return s.substr(minSubStrStartPos, minSubStrLen);
        } else {
            return "";
        }
    }
};
