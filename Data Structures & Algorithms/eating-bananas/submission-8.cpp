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
        for (int k = 1; k <= maxK; ++k) {
            if (canEatAtRate(k)) {
                return k;
            }
        }

        return -1;
    }
};
