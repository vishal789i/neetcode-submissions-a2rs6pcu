class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for (auto num : nums) mp[num]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        for (auto it : mp) {
            minHeap.push({it.second, it.first});
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
