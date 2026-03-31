class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> adj(26);
        vector<int> present(26);
        for (auto& w : words) {
            for (auto ch : w) {
                present[ch - 'a'] = 1;
            }
        }

        for (int i = 1; i < words.size(); ++i) {
            auto &w1 = words[i - 1], &w2 = words[i];
            bool found = false;
            for (int j = 0; j < min(w1.size(), w2.size()); ++j) {
                if (w1[j] != w2[j]) {
                    auto u = w1[j] - 'a', v = w2[j] - 'a';
                    if (find(adj[u].begin(), adj[u].end(), v) == adj[u].end()) {
                        adj[w1[j] - 'a'].push_back(w2[j] - 'a');
                    }

                    found = true;
                    break;
                }
            }

            if (not found and w1.size() > w2.size()) {
                return  "";
            }
        }
        
        string res;
        vector<int> vis(26);
        function<bool(int)> dfs = [&] (int cur) {
            vis[cur] = 1;
            for (auto nei : adj[cur]) {
                if (vis[nei] == 0) {
                    if (not dfs(nei)) {
                        return false;
                    }
                } else if (vis[nei] == 1) {
                    return false;
                }
            }

            vis[cur] = 2;
            res.push_back(cur + 'a');
            return true;
        };

        for (int i = 0; i < 26; ++i) {
            if (present[i] and not vis[i]) {
                if (not dfs(i)) {
                    return "";
                }
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};