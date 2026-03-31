class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); ++i) {
            auto& e = edges[i];
            adj[e[0]].push_back({e[1], succProb[i]});
            adj[e[1]].push_back({e[0], succProb[i]});
        }

        vector<double> best(n);
        best[start_node] = 1.0;
        priority_queue<pair<double, int>> maxHeap;
        maxHeap.push({1, start_node});
        while (not maxHeap.empty()) {
            auto [curProb, cur] = maxHeap.top();
            maxHeap.pop();
            if (cur == end_node) {
                return curProb;
            }

            for (auto [nei, prob] : adj[cur]) {
                auto newProb = prob * curProb;
                if (newProb > best[nei]) {
                    best[nei] = newProb;
                    maxHeap.push({newProb, nei});
                }
            }
        }

        return 0;
    }
};