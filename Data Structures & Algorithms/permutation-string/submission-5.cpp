class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        auto&& checkIfPermutation = [] (std::string& str1, std::string& str2) -> bool {
            if (str1.size() != str2.size()) {
                return false;
            }

            std::vector<int> countVec(26);
            for (auto ch : str1) {
                countVec[ch - 'a']++;
            }
            
            for (auto ch : str2) {
                countVec[ch - 'a']--;
            }

            for (int i = 0; i < 26; ++i) {
                if (countVec[i] != 0) {
                    return false;
                }
            }
            return true;
        };

        int l = 0, r = s1.size() - 1;
        while (r < s2.size()) {
            std::string tempStr(s2.begin() + l, s2.begin() + r + 1);
            if (checkIfPermutation(tempStr, s1)) {
                return true;
            }
            l++;
            r++;
        }
        return false;
    }
};
