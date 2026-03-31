class Solution {
public:
    int minOperations(vector<string>& logs) {
        int res = 0;
        for (auto& l : logs) {
            if (l == "../") {
                res--;
                if (res < 0) {
                    res = 0;
                }
            } else if (l == "./") {
                continue;
            } else {
                res++;
            }
        }

        return res;
    }
};