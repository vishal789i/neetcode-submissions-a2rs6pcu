class Solution {
public:
    string minWindow(string s, string t) {
        if (t == "")
            return "";

        int l = 0, r = 0;
        int have = 0, need = 0;
        // unordered_map<char, int> tCount, windowCount;
        vector<int> tCount(255), windowCount(255);

        for (int i = 0; i < t.size(); ++i)
            tCount[t[i]] += 1;

        for (int count : tCount)
            if (count > 0)
                need += 1;

        int minWindowLen = INT_MAX;
        int minWindowStart = 0;

        while (r < s.size()) {
            windowCount[s[r]] += 1;

            if (tCount[s[r]] > 0 and tCount[s[r]] == windowCount[s[r]])
                have += 1;

            while (have == need) {
                if (r - l + 1 < minWindowLen) {
                    minWindowLen = r - l + 1;
                    minWindowStart = l;
                }

                windowCount[s[l]] -= 1;
                
                if (tCount[s[l]] > 0 and windowCount[s[l]] < tCount[s[l]])
                    have -= 1;

                l += 1;
            }
            r += 1;            
        }

        if (minWindowLen != INT_MAX)
            return s.substr(minWindowStart, minWindowLen);
        return "";
    }
};
