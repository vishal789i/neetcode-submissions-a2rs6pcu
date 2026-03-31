class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<string> stk;
        for (string op : operations) {
            if (op == "+") {
                auto a = stoi(stk.top());
                stk.pop();
                auto b = stoi(stk.top());
                stk.pop();
                stk.push(to_string(b));
                stk.push(to_string(a));
                stk.push(to_string(a + b));
            } else if (op == "C") {
                stk.pop();
            } else if (op == "D") {
                stk.push(to_string(stoi(stk.top()) * 2));
            } else {
                stk.push(op);
            }
        }

        int res = 0;
        while (not stk.empty()) {
            res += stoi(stk.top());
            stk.pop();
        }

        return res;
    }
};