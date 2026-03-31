class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        vector<string> stk;
        string temp;
        while (getline(ss, temp, '/')) {
            if (temp == "..") {
                if (not stk.empty()) {
                    stk.pop_back();
                }
            } else if (not temp.empty() and temp != ".") {
                stk.push_back(temp);
            }
        }

        string res = "";
        for (auto s : stk) {
            res += '/' + s;
        }

        return res.empty() ? "/" : res;
    }
};