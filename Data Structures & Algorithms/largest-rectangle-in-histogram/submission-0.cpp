class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            int minHeightTillNow = heights[i];
            for (int j = i; j < heights.size(); ++j) {
                minHeightTillNow = min(minHeightTillNow, heights[j]);
                int area = (j - i + 1) * minHeightTillNow;
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};
