class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxAreaW = 0;
        for (int i=0; i<heights.size(); ++i) {
            for (int j=i+1; j<heights.size(); ++j) {
                int area = (j-i) * min(heights[i], heights[j]);
                maxAreaW = max(maxAreaW, area);
            }
        }
        return maxAreaW;
    }
};
