class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt = 0;
        for (auto& l : logs) {
            if (l == "../") {
                cnt = max(cnt - 1, 0);
            } else if (l == "./") {
                continue;
            } else {
                cnt++;
            }
        }

        return cnt;
    }
};