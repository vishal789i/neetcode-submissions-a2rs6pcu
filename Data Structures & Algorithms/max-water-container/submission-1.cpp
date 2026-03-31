class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxAreaW = 0;
        int l = 0, r = heights.size() - 1;
        while (l < r) {
            int area = min(heights[l], heights[r]) * (r - l);
            maxAreaW = max(maxAreaW, area);
            if (heights[l] < heights[r]) {
                l++;
            } else if (heights[l] > heights[r]) {
                r--;
            } else {
                r--;
            }
        }
        return maxAreaW;
    }
};
