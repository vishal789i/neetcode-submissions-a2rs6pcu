class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        auto comp = [&] (int a, int b) {
            if (abs(a - x) == abs(b - x)) {
                return a < b;
            }

            return abs(a - x) < abs(b - x);
        };

        priority_queue<int, vector<int>, decltype(comp)> maxHeap(comp);
        for (int n : nums) {
            maxHeap.push(n);
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<int> res;
        while (!maxHeap.empty()) {
            res.push_back(maxHeap.top());
            maxHeap.pop();
        }

        sort(res.begin(), res.end());
        return res;
    }
};