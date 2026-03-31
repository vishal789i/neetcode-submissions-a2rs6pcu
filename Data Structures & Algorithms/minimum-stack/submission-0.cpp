class MinStack {
    stack<int> m_Stk;
    stack<int> m_MinStk;
public:
    MinStack() {}
    
    void push(int val) {
        m_Stk.push(val);
        if (not m_MinStk.empty()) {
            val = min(val, m_MinStk.top());
        }
        m_MinStk.push(val);
    }
    
    void pop() {
        m_Stk.pop();
        m_MinStk.pop();
    }
    
    int top() {
        return m_Stk.top();
    }
    
    int getMin() {
        return m_MinStk.top();
    }
};
