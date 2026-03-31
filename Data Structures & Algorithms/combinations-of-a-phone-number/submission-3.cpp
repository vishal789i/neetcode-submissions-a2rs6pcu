class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> num2Chars = {
            {'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
            {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}
        };

        vector<string> res;
        if (digits.empty()) {
            return res;
        }

        string op;
        function<void(int)> dfs = [&] (int i) {
            if (i == digits.size()) {
                res.push_back(op);
                return;
            }

            for (auto ch : num2Chars[digits[i]]) {
                op.push_back(ch);
                dfs(i + 1);
                op.pop_back();
            }
        };

        dfs(0);
        return res;
    }
};
