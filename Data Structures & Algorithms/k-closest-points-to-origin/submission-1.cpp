class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>> pq;
        for (auto& p : points) {
            pq.push({sqrt(pow(p[0], 2) + pow(p[1], 2)), p});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> res;
        while (not pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
