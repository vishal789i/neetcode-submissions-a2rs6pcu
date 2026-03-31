class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end()), r = accumulate(weights.begin(), weights.end(), 0);
        int res = r;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int curDays = 1;
            int curWt = 0;
            for (auto w : weights) {
                if (curWt + w > m) {
                    curDays++;
                    curWt = 0;
                }

                curWt += w;
            }

            if (curDays <= days) {
                r = m - 1;
                res = m;
            } else {
                l = m + 1;
            }
        }

        return res;
    }
};