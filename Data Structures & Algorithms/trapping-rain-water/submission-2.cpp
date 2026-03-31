class Solution {
public:
    int trap(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int leftMax = heights[l], rightMax = heights[r];
        int maxWater = 0;
        while (l < r) {
            if (leftMax < rightMax) {
                l++;
                leftMax = max(leftMax, heights[l]);
                maxWater += leftMax - heights[l];
            } else {
                r--;
                rightMax = max(rightMax, heights[r]);
                maxWater += rightMax - heights[r];
            }
        }
        
        return maxWater;
    }
};
