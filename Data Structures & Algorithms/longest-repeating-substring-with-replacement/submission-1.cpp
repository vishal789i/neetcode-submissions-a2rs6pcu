class Solution {
public:
    int characterReplacement(string s, int k) {
        std::vector<int> countVec(26, 0);
        int l = 0, r = 0, longestSubStrLength = 1;
        while (r < s.size()) {
            countVec[s[r] - 'A']++;

            int maxCount = *max_element(countVec.begin(), countVec.end());
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
