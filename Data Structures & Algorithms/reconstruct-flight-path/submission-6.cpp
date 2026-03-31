class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, priority_queue<string, vector<string>, greater<string>>> vertex2AdjVerticesMinHeapMap;
        for (auto ticket: tickets) {
            vertex2AdjVerticesMinHeapMap[ticket[0]].push(ticket[1]);
        }

        vector<string> res;

        function<void(string)> dfs = [&] (string vertex) {
            auto& adjVerticesMinHeap = vertex2AdjVerticesMinHeapMap[vertex];
            while (not adjVerticesMinHeap.empty()) {
                auto nextVertex = adjVerticesMinHeap.top();
                adjVerticesMinHeap.pop();
                dfs(nextVertex);
            }
            
            res.push_back(vertex);
        };

        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
};
