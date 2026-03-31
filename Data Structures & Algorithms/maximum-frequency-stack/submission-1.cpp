class FreqStack {
    unordered_map<int, stack<int>> cnt2Stk;
    unordered_map<int, int> val2Cnt;
    int maxCnt = 0;

public:
    FreqStack() {}
    
    void push(int val) {
        val2Cnt[val]++;
        auto cnt = val2Cnt[val];
        maxCnt = max(maxCnt, cnt);
        cnt2Stk[cnt].push(val);
    }
    
    int pop() {
        auto& stk = cnt2Stk[maxCnt];
        auto res = stk.top();
        stk.pop();
        val2Cnt[res] -= 1;
        if (stk.empty()) {
            maxCnt -= 1;
        }

        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */