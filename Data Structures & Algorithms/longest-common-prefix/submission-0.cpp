class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        auto it = strs.begin();
        auto& firstStr = *it;
        int minLen = firstStr.size();

        it ++;
        while (it != strs.end()) {
            int i = 0;
            auto& curStr = *it;
            while (i < minLen and i < curStr.size() and curStr[i] == firstStr[i]) {
                i++;
            }
            
            minLen = i;
            if (i == 0) {
                break;
            }
            it ++;
        }

        return firstStr.substr(0, minLen);
    }
};