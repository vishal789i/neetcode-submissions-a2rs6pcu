class Solution {
public:
    int maxDifference(string s) {
        vector<int> counts(26);
        for (auto ch : s) {
            counts[ch - 'a']++;
        }

        int maxOddF = 0, maxDiff = INT_MIN, minEvenF = INT_MAX;
        for (int i = 0; i < 26; ++i) {
            if (counts[i] > 0 and counts[i] % 2 == 0) {
                minEvenF = min(minEvenF, counts[i]);
            } else {
                maxOddF = max(maxOddF, counts[i]);
            }
        }

        return maxOddF - minEvenF;
    }
};