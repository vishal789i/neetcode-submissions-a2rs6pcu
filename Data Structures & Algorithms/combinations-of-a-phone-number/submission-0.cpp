class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        
        unordered_map<char, string> digit2Chars = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, 
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

        vector<string> ans;
        
        function<void(string&, int)> solve = [&digits, &digit2Chars, &solve, &ans] (string& op, int i) {
            if (op.size() == digits.size()) {
                ans.push_back(op);
                return;
            }

            for (auto ch : digit2Chars[digits[i]]) {
                op.push_back(ch);
                solve(op, i + 1);
                op.pop_back();
            }
        };

        string op = "";
        solve(op, 0);
        return ans;
    }
};
