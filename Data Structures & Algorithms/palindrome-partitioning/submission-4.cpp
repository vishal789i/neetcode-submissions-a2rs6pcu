class Solution {
public:
    bool isPalindrome(string& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> res;
        vector<string> temp;
        function<void(int)> dfs = [&] (int i) {
            if (i == s.size()) {
                res.push_back(temp);
                return;
            }
            
            std::string curStr;
            for (int j = i; j < n; ++j) {
                curStr += s[j];
                if (isPalindrome(curStr)) {
                    temp.push_back(curStr);
                    dfs(j + 1);
                    temp.pop_back();
                }
            }
        };

        dfs(0);
        return res;
    }
};
