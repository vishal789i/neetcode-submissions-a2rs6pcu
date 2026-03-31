class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap(stones.begin(), stones.end());
        while (maxHeap.size() > 1) {
            auto a = maxHeap.top();
            maxHeap.pop();
            auto b = maxHeap.top();
            maxHeap.pop();
            if (a != b) {
                maxHeap.push(abs(a - b));
            }
        }

        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
