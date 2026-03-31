class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> tChar2Count, windowChar2Count;
        for (auto c : t) tChar2Count[c] ++;

        auto need = tChar2Count.size();
        auto have = 0;
        int r = 0, l = 0;
        int minStart = 0, minSize = INT_MAX;
        while (r < s.size()) {
            auto rightChar = s[r];
            windowChar2Count[rightChar] ++;

            if (tChar2Count.count(rightChar) and windowChar2Count[rightChar] == tChar2Count[rightChar]) {
                have ++;
            }

            while (have == need) {
                if (r - l + 1 < minSize) {
                    minSize = r - l + 1;
                    minStart = l;
                }

                auto leftChar = s[l];
                windowChar2Count[leftChar] --;

                if (tChar2Count.count(leftChar) and windowChar2Count[leftChar] < tChar2Count[leftChar]) {
                    have --;
                }

                l ++;
            }
            r ++;
        }

        return minSize == INT_MAX ? "" : s.substr(minStart, minSize);
    }
};
