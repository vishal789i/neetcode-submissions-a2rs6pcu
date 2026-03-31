class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) {
            return 0;
        }

        int lMax = heights[0], rMax = heights[n - 1];
        int l = 0, r = n - 1, res = 0;
        while (l < r) {
            if (lMax <= rMax) {
                res += lMax - heights[l];
                l++;
                lMax = max(lMax, heights[l]);
            } else {
                res += rMax - heights[r];
                r--;
                rMax = max(rMax, heights[r]);
            }
        }

        return res;
    }
};