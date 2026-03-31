class Solution {
public:
    int characterReplacement(string s, int k) {
        std::vector<int> countVec(26, 0);
        int l = 0, r = 0, longestSubStrLength;
        while (r < s.size()) {
            countVec[s[r] - 'A']++;
            int maxCount = 0;
            for (int i = 0; i < countVec.size(); ++i) {
                maxCount = max(maxCount, countVec[i]);
            }
            
            int currLength = r - l + 1;
            if (currLength - maxCount <= k) {
                longestSubStrLength = max(longestSubStrLength, currLength);
            } else {
                countVec[s[l] - 'A']--;
                l++;
            }
            r++;
        }
        return longestSubStrLength;
    }
};
