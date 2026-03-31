class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> maxHeap;
        for (auto g : gifts) {
            maxHeap.push(g);
        }
        
        while (k--) {
            maxHeap.push(sqrt(maxHeap.top()));
            maxHeap.pop();
        }

        long long res = 0;
        while (not maxHeap.empty()) {
            res += maxHeap.top();
            maxHeap.pop();
        }

        return res;
    }
};