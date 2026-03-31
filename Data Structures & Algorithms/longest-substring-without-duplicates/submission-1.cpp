class Solution {
public:
    bool isUniqueStr(std::string str) {
        std::unordered_set<char> s;
        for (auto ch: str) {
            if (s.count(ch) != 0) {
                return false;
            }
            s.insert(ch);
        }
        return true;
    }

    int lengthOfLongestSubstring(string s) {
        if (s == "") {
            return 0;
        }
        
        int maxLength = 1;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i + 1; j < s.size(); ++j) {
                std::string subStr = "";
                for (int k = i; k <= j; ++k) {
                    subStr += s[k];
                }

                int subStrLen = subStr.size();
                if (isUniqueStr(subStr)) {
                    maxLength = max(maxLength, subStrLen);
                }
            }
        }
        return maxLength;
    }
};
