class Solution {
public:
    int heightChecker(vector<int>& heights) {
        auto sortedHeights = heights;
        sort(begin(sortedHeights), end(sortedHeights));
        int res = 0;
        for (int i = 0; i < heights.size(); ++i) {
            if (sortedHeights[i] != heights[i]) {
                res++;
            }
        }

        return res;
    }
};