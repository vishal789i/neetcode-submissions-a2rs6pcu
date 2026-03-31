class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int res = r;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int hrs = 0;
            for (auto p : piles) {
                hrs += ceil((double)p / m);
            }

            if (hrs <= h) {
                r = m - 1;
                res = m;
            } else {
                l = m + 1;
            }
        }

        return res;
    }
};
