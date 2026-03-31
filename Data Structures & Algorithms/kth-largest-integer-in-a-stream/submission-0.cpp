class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int m_K;
    KthLargest(int k, vector<int>& nums) {
        m_K = k;
        for (auto num: nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        auto k = m_K;

        pq.push(val);
        if (pq.size() > k) {
            pq.pop();
        }

        return pq.top();
    }
};
