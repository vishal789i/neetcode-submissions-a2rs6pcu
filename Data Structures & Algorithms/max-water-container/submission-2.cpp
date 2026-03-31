class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1, maxA = 0;
        while (l < r) {
            maxA = max(maxA, min(heights[l], heights[r]) * (r - l));
            if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return maxA;
    }
};
