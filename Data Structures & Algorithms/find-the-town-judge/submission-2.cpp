class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> outdegrees(n + 1), indegrees(n + 1);
        for (auto& t : trust) {
            outdegrees[t[0]]++;
            indegrees[t[1]]++;
        }

        for (int i = 1; i <= n; ++i) {
            if (outdegrees[i] == 0 and indegrees[i] == n - 1) {
                return i;
            }
        }
        return -1;
    }
};