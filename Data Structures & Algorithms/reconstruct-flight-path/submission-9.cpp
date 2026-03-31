class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end());
        map<string, vector<string>> adj;
        for (auto& t : tickets) {
            adj[t[0]].push_back(t[1]);
        }
 
        vector<string> res{"JFK"};
        function<bool(string&)> dfs = [&] (string& cur) {
            if (res.size() == tickets.size() + 1) {
                return true;
            }

            if (not adj.contains(cur)) {
                return false;
            }

            auto temp = adj[cur];
            for (int i = 0; i < temp.size(); ++i) {
                string nextV = temp[i];
                adj[cur].erase(adj[cur].begin() + i);
                res.push_back(nextV);
                if (dfs(nextV)) {
                    return true;
                }

                res.pop_back();
                adj[cur].insert(adj[cur].begin() + i, nextV);
            }

            return false;
        };

        string start = "JFK";
        dfs(start);
        return res;
    }
};
