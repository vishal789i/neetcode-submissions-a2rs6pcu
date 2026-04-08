class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        vector<int> dists(n, 1e9);
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;
        minHeap.push({0, 0, src});
        dists[src] = 0;
        while (not minHeap.empty()) {
            auto [stops, dist, node] = minHeap.top();
            minHeap.pop();
            if (stops > k) {
                continue;
            }

            for (auto [nei, neiDist] : adj[node]) {
                if (dist + neiDist < dists[nei]) {
                    dists[nei] = dist + neiDist;
                    minHeap.push({stops + 1, dist + neiDist, nei});
                }
            }
        }

        if (dists[dst] == 1e9) {
            return -1;
        }

        return dists[dst];
    }
};
