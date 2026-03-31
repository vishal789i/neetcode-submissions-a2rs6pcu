class Solution {
public:
    int characterReplacement(string s, int replacableChars) {
        int longestLength = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i + 1; j < s.size(); ++j) {
                std::vector<int> countVec(26);
                std::string subStr = "";
                for (int k = i; k <= j; k++) {
                    subStr += s[k];
                    countVec[s[k] - 'A']++;
                }
    
                int maxCount = *max_element(countVec.begin(), countVec.end());
                if ((int)subStr.size() - maxCount <= replacableChars) {
                    longestLength = max(longestLength, (int)subStr.size());
                }
            }
        }
        return longestLength;
    }
};
