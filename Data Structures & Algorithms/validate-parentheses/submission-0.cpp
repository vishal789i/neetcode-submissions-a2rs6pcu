class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> close2Open;
        close2Open['}'] = '{';
        close2Open[')'] = '(';
        close2Open[']'] = '[';

        stack<char> stk;
        for (char ch : s) {
            if (close2Open[ch]) { // ch is a closing brace
                if (!stk.empty() and stk.top() == close2Open[ch]) {
                    stk.pop();
                } else {
                    return false;
                }
            } else { // ch is a opening brace, push to stack
                stk.push(ch);
            }
        }

        return stk.empty() ? true : false;
    }
};
