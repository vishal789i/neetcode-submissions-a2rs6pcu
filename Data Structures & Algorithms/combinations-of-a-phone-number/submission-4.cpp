class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> digit2Chars{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        int N = digits.size();
        vector<string> res;
        if (N == 0) {
            return res;
        }
        
        function<void(int, string)> dfs = [&] (int i, string op) {
            if (op.size() == N) {
                res.push_back(op);
                return;
            }
            
            for (char ch : digit2Chars[digits[i]]) {
                dfs(i + 1, op + ch);
            }
        };

        dfs(0, "");
        return res;
    }
};
