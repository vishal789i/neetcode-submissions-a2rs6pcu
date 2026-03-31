class Solution {
public:
    string decodeString(string s) {
        vector<string> stk;
        for (auto ch : s) {
            if (ch != ']') {
                stk.push_back(string(1, ch));
            } else {
                string substr = "";
                while (not stk.empty() and stk.back() != "[") {
                    substr = stk.back() + substr;
                    stk.pop_back();
                }

                stk.pop_back();
                string numStr = "";
                while (not stk.empty() and isdigit(stk.back()[0])) {
                    numStr = stk.back() + numStr;
                    stk.pop_back();
                }

                auto num = stoi(numStr);
                string repeated = "";
                while (num--) {
                    repeated += substr;
                }

                stk.push_back(repeated);
            }
        }

        string res = "";
        for (auto str : stk) {
            res += str;
        }

        return res;
    }
};