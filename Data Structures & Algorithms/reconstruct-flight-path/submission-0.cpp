class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end());

        map<string, vector<string>> vertex2AdjVerticesMap;
        for (auto ticket: tickets) {
            vertex2AdjVerticesMap[ticket[0]].push_back(ticket[1]);
        }

        vector<string> res = {"JFK"};

        function<bool(string)> dfs = [&] (string vertex) {
            if (res.size() == tickets.size() + 1) {
                return true;
            }

            if (not vertex2AdjVerticesMap.count(vertex)) {
                return false;
            }

            auto temp = vertex2AdjVerticesMap[vertex];
            for (int i = 0; i < temp.size(); ++i) {
                res.push_back(temp[i]);
                vertex2AdjVerticesMap[vertex].erase(vertex2AdjVerticesMap[vertex].begin() + i);
                if (dfs(temp[i])) {
                    return true;
                }
                vertex2AdjVerticesMap[vertex].insert(vertex2AdjVerticesMap[vertex].begin() + i, temp[i]);
                res.pop_back();
            }

            return false;
        };

        string src = "JFK";
        dfs(src);
        return res;
    }
};
