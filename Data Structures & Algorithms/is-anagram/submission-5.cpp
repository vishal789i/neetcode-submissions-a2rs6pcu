class Solution {
public:
    bool isAnagram(string s, string t) {
        std::map<char, int> char2Count;
        for (auto sCh : s) {
            char2Count[sCh]++;
        }

        for (auto tCh : t) {
            char2Count[tCh]--;
        }

        for (auto [ch, count] : char2Count) {
            if (count != 0) {
                return false;
            }
        }
        return true;
    }
};
