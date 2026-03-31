class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> m_LargeElemMinHeap;
    priority_queue<int> m_SmallElemMaxHeap;

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
        int n1 = 0, n2 = 0;
        if (m_SmallElemMaxHeap.size() == m_LargeElemMinHeap.size()) {
            return (m_SmallElemMaxHeap.top() + m_LargeElemMinHeap.top()) / 2.0;
        } else if (m_SmallElemMaxHeap.size() > m_LargeElemMinHeap.size()) {
            return m_SmallElemMaxHeap.top();
        } else {
            return m_LargeElemMinHeap.top();
        }
    }
};
