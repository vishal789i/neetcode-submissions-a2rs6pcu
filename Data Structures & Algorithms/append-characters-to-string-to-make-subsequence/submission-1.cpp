class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0, j = 0;
        while (i < s.size() and j < t.size()) {
            if (s[i] != t[j]) {
                i++;
            } else {
                i++;
                j++;
            }
        }

        return t.size() - j;
    }
};