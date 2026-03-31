class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, int>> maxHeap;

        for (int i = 0; i < points.size(); ++i) {
            maxHeap.push({pow(pow(points[i][0], 2) + pow(points[i][1], 2), 0.5), i});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<vector<int>> res;
        while (not maxHeap.empty()) {
            auto pointIdx = maxHeap.top().second;
            maxHeap.pop();
            auto point = points[pointIdx];
            res.push_back(points[pointIdx]);
        }
        return res;
    }
};
