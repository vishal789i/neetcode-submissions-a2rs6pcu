class Solution {
public:
    int trap(vector<int>& heights) {
        std::vector<int> maxLefts(heights.size());
        int maxTillNow = 0;
        for (int i=0; i<heights.size(); ++i) {
            maxTillNow = max(maxTillNow, heights[i]);
            maxLefts[i] = maxTillNow;
        }
        maxTillNow = 0;
        std::vector<int> maxRights(heights.size());
        for (int i=heights.size()-1; i>=0; --i) {
            maxTillNow = max(maxTillNow, heights[i]);
            maxRights[i] = maxTillNow;
        }

        vector<int> results(heights.size());
        int maxWater = 0;
        for (int i=0; i<heights.size(); ++i) {
            int currWater = min(maxLefts[i], maxRights[i]) - heights[i];
            if (currWater >= 0) {
                maxWater += currWater;
            }
        }
        
        return maxWater;
    }
};
