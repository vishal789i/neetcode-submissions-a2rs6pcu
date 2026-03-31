class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        function<void(int, vector<string>&)> solve = [&s, &ans, &solve] (int startIdx, vector<string>& op) {
            if (startIdx == s.size()) {
                ans.push_back(op);
                return;
            }

            string currStr = "";
            for (int i = startIdx; i < s.size(); ++i) {
                currStr += s[i];
                auto isPalindrome = [&currStr] () {
                    int l = 0;
                    int r = currStr.size() - 1;
                    while (l <= r) {
                        if (currStr[l] != currStr[r]) {
                            return false;
                        }
                        l++;
                        r--;
                    }
                    return true;
                };
                
                if (isPalindrome()) {
                    op.push_back(currStr);
                    solve(i + 1, op);
                    op.pop_back();
                }
            }
        };
        
        vector<string> op;
        solve(0, op);
        return ans;
    }
};
