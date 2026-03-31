class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, priority_queue<string, vector<string>, greater<>>> adj;
        for (auto& t : tickets) {
            adj[t[0]].push(t[1]);
        }

        vector<string> res;
        function<void(string&)> dfs = [&] (string& cur) {
            while (not adj[cur].empty()) {
                auto nextDest = adj[cur].top();
                adj[cur].pop();
                dfs(nextDest);
            }

            res.push_back(cur);
        };

        string start = "JFK";
        dfs(start);
        reverse(res.begin(), res.end());
        return res;
    }
};
