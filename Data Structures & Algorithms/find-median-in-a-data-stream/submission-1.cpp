class MedianFinder {
    priority_queue<int> m_SmallElemMaxHeap;
    priority_queue<int, vector<int>, greater<>> m_LargeElemMinHeap;

public:
    MedianFinder() {}
    
    void addNum(int num) {
        m_SmallElemMaxHeap.push(num);

        if (m_SmallElemMaxHeap.size() > m_LargeElemMinHeap.size() + 1) {
            m_LargeElemMinHeap.push(m_SmallElemMaxHeap.top());
            m_SmallElemMaxHeap.pop();
        }

        if (not m_LargeElemMinHeap.empty() and m_SmallElemMaxHeap.top() > m_LargeElemMinHeap.top()) {
            m_LargeElemMinHeap.push(m_SmallElemMaxHeap.top());
            m_SmallElemMaxHeap.pop();
        }

        if (m_LargeElemMinHeap.size() > m_SmallElemMaxHeap.size() + 1) {
            m_SmallElemMaxHeap.push(m_LargeElemMinHeap.top());
            m_LargeElemMinHeap.pop();
        }
    }
    
    double findMedian() {
        if (m_LargeElemMinHeap.size() == m_SmallElemMaxHeap.size()) {
            return (m_LargeElemMinHeap.top() + m_SmallElemMaxHeap.top()) / 2.0;
        } else if (m_LargeElemMinHeap.size() > m_SmallElemMaxHeap.size()) {
            return m_LargeElemMinHeap.top();
        } else {
            return m_SmallElemMaxHeap.top();
        }
    }
};
