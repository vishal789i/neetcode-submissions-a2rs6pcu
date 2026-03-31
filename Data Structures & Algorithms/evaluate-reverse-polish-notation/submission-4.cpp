class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string& t : tokens) {
            if (t == "+") {
                auto a = st.top(); st.pop();
                auto b = st.top(); st.pop();
                st.push(a + b);
            } else if (t == "-") {
                auto a = st.top(); st.pop();
                auto b = st.top(); st.pop();
                st.push(b - a);
            } else if (t == "*") {
                auto a = st.top(); st.pop();
                auto b = st.top(); st.pop();
                st.push(a * b);
            } else if (t == "/") {
                auto a = st.top(); st.pop();
                auto b = st.top(); st.pop();
                st.push(b / a);
            } else {
                st.push(stoi(t));
            }
        }

        return st.top();
    }
};
