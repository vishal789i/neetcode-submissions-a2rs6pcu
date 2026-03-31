class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        for (int i = 0; i < nums.size(); ++i) {
            minHeap.push({nums[i], i});
        }

        while (k--) {
            auto [num, idx] = minHeap.top();
            minHeap.pop();
            minHeap.push({num * multiplier, idx});
        }

        vector<int> res(nums.size());
        while (not minHeap.empty()) {
            auto [num, idx] = minHeap.top();
            minHeap.pop();
            res[idx] = num;
        }

        return res;
    }
};