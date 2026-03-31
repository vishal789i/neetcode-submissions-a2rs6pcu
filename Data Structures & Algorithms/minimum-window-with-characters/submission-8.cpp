class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> tChar2Freq;
        for (auto ch : t) {
            tChar2Freq[ch]++;
        }
        int l = 0, r = 0, minStart = 0, minSize = INT_MAX, count = tChar2Freq.size();
        while (r < s.size()) {
            if (tChar2Freq.count(s[r])) {
                tChar2Freq[s[r]]--;
                if (tChar2Freq[s[r]] == 0) {
                    count--;
                }
            }

            while (count == 0) {
                if (tChar2Freq.count(s[l])) {
                    tChar2Freq[s[l]]++;
                    if (tChar2Freq[s[l]] > 0) {
                        count++;
                    }
                    
                    if (r - l + 1 < minSize) {
                        minSize = r - l + 1;
                        minStart = l;
                    }
                }
                l++;
            }
            r++;
        }

        return minSize == INT_MAX ? "" : s.substr(minStart, minSize);
    }
};
