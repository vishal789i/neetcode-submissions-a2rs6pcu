class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<int> parent(accounts.size()), size(accounts.size(), 1);
        for (auto i = 0; i < accounts.size(); ++i) {
            parent[i] = i;
        }

        auto find = [&] (int u) {
            while (u != parent[u]) {
                u = parent[u];
                parent[u] = parent[parent[u]];
            }

            return u;
        };

        auto unite = [&] (int u, int v) {
            auto pu = find(u), pv = find(v);
            if (pu == pv) {
                return;
            }

            if (size[pu] >= size[pv]) {
                size[pu] += size[pv];
                parent[pv] = pu;
            } else {
                size[pv] += size[pu];
                parent[pu] = pv;
            }
        };

        map<string, int> email2Id;
        for (int id = 0; id < accounts.size(); ++id) {
            for (int j = 1; j < accounts[id].size(); ++j) {
                auto& email = accounts[id][j];
                if (email2Id.contains(email)) {
                    auto existingId = email2Id.at(email);
                    unite(id, existingId);
                } else {
                    email2Id.insert({email, id});
                }
            }
        }

        map<int, vector<string>> id2Emails;
        for (auto [email, id] : email2Id) {
            id2Emails[find(id)].push_back(email);
        }

        vector<vector<string>> res;
        for (auto [id, emails] : id2Emails) {
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), accounts[id][0]);
            res.push_back(emails);
        }

        return res;
    }
};