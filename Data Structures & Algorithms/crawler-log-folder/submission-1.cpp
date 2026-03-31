class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> stk;
        for (auto& l : logs) {
            if (l == "../") {
                if (not stk.empty()) {
                    stk.pop();
                }
            } else if (l == "./") {
                continue;
            } else {
                stk.push(l);
            }
        }

        return stk.size();
    }
};