class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());;
        int res = r;
        while (l <= r) {
            int k = (l + r) / 2;
            int hrs = 0;
            for (auto pile : piles) {
                hrs += ceil((double)pile / k);
            }

            if (hrs <= h) {     // found ans, try smaller k
                r = k - 1;
                res = k;
            } else {
                l = k + 1;
            }
        }
        
        return res;
    }
};
