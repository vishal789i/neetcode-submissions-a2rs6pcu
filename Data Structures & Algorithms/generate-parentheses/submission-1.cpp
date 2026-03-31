class Solution {
public:
    vector<string> res;
    void backtrack(int openN, int closedN, int n, string path) {
        if (openN == closedN and openN == n) {
            res.push_back(path);
            return;
        }

        if (openN < n) {
            backtrack(openN + 1, closedN, n, path + "(");
        }

        if (closedN < openN) {
            backtrack(openN, closedN + 1, n, path + ")");
        }
    }

    vector<string> generateParenthesis(int n) {
        string path = "";
        backtrack(0, 0, n, path);
        return res;
    }
};
