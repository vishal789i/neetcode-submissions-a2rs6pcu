class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto canEatAtRate = [&] (int k) {
            int totalHrs = 0;
            for (auto p : piles) {
                totalHrs += ceil(p / static_cast<double>(k));
            }

            cout << k << ' ' << totalHrs << endl;

            return totalHrs <= h;
        };

        int maxK = *max_element(piles.begin(), piles.end());
        int res = 0;
        int l = 1, r = maxK;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (canEatAtRate(m)) {
                res = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        
        return res;
    }
};
