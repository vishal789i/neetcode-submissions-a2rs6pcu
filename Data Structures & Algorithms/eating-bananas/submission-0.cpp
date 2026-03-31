class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        
        int minEatingRate = 0;
        while (l <= r) {
            int currRate = (l + r) / 2;

            int currTotalHrs = 0;
            for (int pile : piles)
                currTotalHrs += ceil(static_cast<double>(pile) / currRate );

            if (currTotalHrs <= h) {
                minEatingRate = currRate;
                r = currRate - 1;
            } else {
                l = currRate + 1;
            }
        }
        return minEatingRate;
    }
};
