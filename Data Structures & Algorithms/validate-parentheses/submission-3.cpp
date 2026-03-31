class Solution {
public:
    bool isValid(string s) {
        map<char, char> open2Close {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'}
        };

        stack<int> stk;
        for (int i = 0; i < s.size(); ++i) {
            if (open2Close.count(s[i])) {
                stk.push(s[i]);
            } else {
                if (stk.empty()) {
                    return false;
                } else if (open2Close[stk.top()] == s[i]) {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }

        return stk.empty();
    }
};
