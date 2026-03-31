class Solution {
public:
    bool isAnagram(string s, string t) {         
        if (s.size() != t.size()) {
            return false;
        }

        std::array<int, 27> sFreq, tFreq;
        sFreq.fill(0);
        tFreq.fill(0);
        
        for (int i=0; i<s.size(); ++i) {
            sFreq[s[i] - 'a']++;
            tFreq[t[i] - 'a']++;
        }

        for (int i=0; i<27; ++i) {
            if (sFreq[i] != tFreq[i]) {
                return false;
            }
        }
        return true;
    }
};
