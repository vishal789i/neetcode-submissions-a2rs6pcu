class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        for (int i = 0; i < capital.size(); ++i) {
            minHeap.push({capital[i], profits[i]});
        }

        priority_queue<int> maxHeap;
        while (k--) {
            while (not minHeap.empty() and minHeap.top().first <= w) {
                maxHeap.push(minHeap.top().second);
                minHeap.pop();
            }

            if (maxHeap.empty()) {
                break;
            }

            w += maxHeap.top();
            maxHeap.pop();
        }

        return w;
    }
};