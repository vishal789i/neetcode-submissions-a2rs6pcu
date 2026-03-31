class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int res = 0;
        while (l < r) {
            if (heights[l] > heights[r]) {
                res = max(res, (r - l) * heights[r]);
                r--;
            } else {
                res = max(res, (r - l) * heights[l]);
                l++;
            }
        }

        return res;
    }
};
