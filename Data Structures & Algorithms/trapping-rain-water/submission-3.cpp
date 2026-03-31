class Solution {
public:
    int trap(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int leftMax = heights[l], rightMax = heights[r];
        int trappedWater = 0;
        while (l <= r) {
            if (leftMax < rightMax) {
                if (heights[l] >= leftMax) {
                    leftMax = heights[l];
                } else {
                    trappedWater += leftMax - heights[l];
                }
                l++;
            } else {
                if (heights[r] >= rightMax) {
                    rightMax = heights[r];
                } else {
                    trappedWater += rightMax - heights[r];
                }
                r--;
            }
        }
        return trappedWater;
    }
};
