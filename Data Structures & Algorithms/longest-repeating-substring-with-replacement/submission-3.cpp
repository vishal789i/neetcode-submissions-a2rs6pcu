class Solution {
public:
    int characterReplacement(string s, int k) {
        int longestLength = 0;
        for (int i = 0; i < s.size(); ++i) {
            std::vector<int> countVec(26);
            int maxCountTillNow = 0;
            for (int j = i; j < s.size(); ++j) {
                countVec[s[j] - 'A']++;
                maxCountTillNow = max(maxCountTillNow, countVec[s[j] - 'A']);
                int subStrLength = j - i + 1;
                if (subStrLength - maxCountTillNow <= k) {
                    longestLength = max(longestLength, subStrLength);
                } else {
                    break;
                }
            }
        }
        return longestLength;
    }
};
