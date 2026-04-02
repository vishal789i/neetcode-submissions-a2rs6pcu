class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for (auto n : nums) {
            mp[n]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        for (auto [n, f] : mp) {
            minHeap.push({f, n});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> res;
        while (not minHeap.empty()) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return res;
    }
};
