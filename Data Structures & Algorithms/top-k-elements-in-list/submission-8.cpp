class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num2Freq;
        for (auto num : nums) {
            num2Freq[num] ++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        for (auto [num, freq] : num2Freq) {
            minHeap.push({freq, num});
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
