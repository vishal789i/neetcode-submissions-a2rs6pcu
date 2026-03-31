class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string minLenWord = "";
        int maxLenOfPrefix = 0;
        for (auto& s : strs) {
            if (maxLenOfPrefix < s.size()) {
                maxLenOfPrefix = s.size();
                minLenWord = s;
            }
        }

        for (int i = 0; i < maxLenOfPrefix; ++i) {
            for (auto& s : strs) {
                if (i == maxLenOfPrefix || s[i] != minLenWord[i]) {
                    return s.substr(0, i);
                }
            }
        }

        return minLenWord;
    }
};