class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (string& token: tokens) {
            if (token == "+") {
                int a = stk.top(); stk.pop();
                int b = stk.top(); stk.pop();
                stk.push(b + a);
            } else if (token == "-") {
                int a = stk.top(); stk.pop();
                int b = stk.top(); stk.pop();
                stk.push(b - a);
            } else if (token == "*") {
                int a = stk.top(); stk.pop();
                int b = stk.top(); stk.pop();
                stk.push(b * a);
            } else if (token == "/") {
                int a = stk.top(); stk.pop();
                int b = stk.top(); stk.pop();
                stk.push(b / a);
            } else {
                stk.push(stoi(token));
            }
        }

        return stk.top(); 
    }
};
