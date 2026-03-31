class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> counts(26), balloonCounts(26);
        for (auto c : text) {
            counts[c - 'a']++;
        }

        for (const auto c : string("balloon")) {
            balloonCounts[c - 'a']++;
        }

        int res = INT_MAX;
        for (int i = 0; i < 26; ++i) {
            if (balloonCounts[i] == 0) {
                continue;
            }

            res = min(res, counts[i] / balloonCounts[i]);
        }
        
        return res;
    }
};