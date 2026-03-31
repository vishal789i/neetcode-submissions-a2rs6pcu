class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        map<int, vector<pair<int, int>>> vertex2AdjVerticesMap;
        for (auto flight: flights) {
            vertex2AdjVerticesMap[flight[0]].push_back({flight[1], flight[2]});
        }

        vector<int> dist(n, INT_MAX);
        queue<tuple<int, int, int>> q; // stops, vertex, cost
        q.push({0, src, 0});
        while (not q.empty()) {
            auto [stops, vertex, cost] = q.front();
            q.pop();

            if (stops > k) {
                continue;
            }

            // stops <= K here
            for (auto [adjVertex, adjVertexCost]: vertex2AdjVerticesMap[vertex]) {
                if (cost + adjVertexCost < dist[adjVertex]) {
                    dist[adjVertex] = cost + adjVertexCost;
                    q.push({stops + 1, adjVertex, cost + adjVertexCost});
                }
            }
        }

        if (dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};
