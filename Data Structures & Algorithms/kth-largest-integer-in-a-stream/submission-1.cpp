class KthLargest {
    priority_queue<int, vector<int>, greater<>> pq;
    int k;

public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (auto n : nums) {
            pq.push(n);
        }
    }
    
    int add(int val) {
        pq.push(val);
        while (pq.size() > k) {
            pq.pop();
        }

        return pq.top();
    }
};
