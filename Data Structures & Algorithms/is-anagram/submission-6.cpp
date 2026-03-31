class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freqs(26, 0);
        for (auto ch : s) {
            freqs[ch - 'a'] ++;
        }

        for (auto ch : t) {
            freqs[ch - 'a'] --;
        }

        for (auto f : freqs) {
            if (f != 0) return false;
        }

        return true;
    }
};
