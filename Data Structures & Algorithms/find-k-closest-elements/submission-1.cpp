class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        // max-heap where we store the k closest elements
        // priority is given to elements with higher absolute diff,
        // and in case of tie, larger number gets higher priority
        auto comp = [x](const int& a, const int& b) {
            if (abs(a - x) == abs(b - x))
                return a < b;  // prefer smaller value
            return abs(a - x) < abs(b - x); // prefer closer
        };
        
        priority_queue<int, vector<int>, decltype(comp)> maxHeap(comp);
        
        for (int num : nums) {
            maxHeap.push(num);
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
