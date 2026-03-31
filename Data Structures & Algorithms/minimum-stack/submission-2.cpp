class MinStack {
    stack<int> stk;
    stack<int> minStk;

public:
    MinStack() {}
    
    void push(int val) {
        stk.push(val);
        if (minStk.empty()) {
            minStk.push(val);
        } else {
            if (val <= minStk.top()) {
                minStk.push(val);
            }
        }
    }
    
    void pop() {
        auto ele = stk.top();
        stk.pop();
        if (not minStk.empty() and ele == minStk.top()) {
            minStk.pop();
        }
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};
