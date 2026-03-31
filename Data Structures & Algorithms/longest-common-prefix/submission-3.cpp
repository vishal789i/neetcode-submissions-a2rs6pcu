class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        auto prefix = strs[0];
        for (auto& s : strs) {
            int j = 0;
            while (j < min(prefix.size(), s.size())) {
                if (prefix[j] != s[j]) break;
                j++;
            }

            prefix = s.substr(0, j);
        }

        return prefix;
    }
};