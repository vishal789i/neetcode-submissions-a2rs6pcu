class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto canEatAtRate = [&] (int k) {
            double hrsTakenToEat = 0;
            for (double p : piles) {
                hrsTakenToEat += ceil(p / k);
                
            }

            return hrsTakenToEat <= h;
        };

        int maxK = *max_element(piles.begin(), piles.end());
        int l = 1, r = maxK;
        int res = -1;
        while (l <= r) {
            int k = l + (r - l) / 2;
            if (canEatAtRate(k)) {
                res = k;
                r = k - 1;
            } else {
                l = k + 1;
            }
        }

        return res;
    }
};
