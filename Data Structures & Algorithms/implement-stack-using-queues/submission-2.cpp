class MyStack {
    queue<int> mainQ;
    queue<int> auxQ;

public:
    MyStack() {    
    }
    
    void push(int x) {
        auxQ.push(x);
        while (not mainQ.empty()) {
            auxQ.push(mainQ.front());
            mainQ.pop();
        }

        swap(mainQ, auxQ);
    }
    
    int pop() {
        int popped = mainQ.front();
        mainQ.pop();
        return popped;
    }
    
    int top() {
        return mainQ.front();
    }
    
    bool empty() {
        return mainQ.empty() and auxQ.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */