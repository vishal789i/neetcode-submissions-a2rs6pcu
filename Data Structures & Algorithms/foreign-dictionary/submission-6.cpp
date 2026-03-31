class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<set<int>> adj(26);
        vector<int> indegrees(26, 0);
        for (int i = 0; i < words.size() - 1; ++i) {
            auto s1 = words[i];
            auto s2 = words[i+1];
            bool found = false;
            auto minLen = min(s1.size(), s2.size());
            for (int j = 0; j < minLen; ++j) {
                if (s1[j] != s2[j]) {
                    if (not adj[s1[j] - 'a'].count(s2[j] - 'a')) {
                        adj[s1[j] - 'a'].insert(s2[j] - 'a');
                        indegrees[s2[j] - 'a']++;
                    }
                    found = true;
                    break;
                }
            }

            if (not found and s1.size() > s2.size()) {
                return "";
            }
        }

        queue<int> q;
        for (int i = 0; i < 26; ++i) {
            if (indegrees[i] == 0) {
                q.push(i);
            }
        }

        string res;
        while (not q.empty()) {
            auto vertex = q.front();
            q.pop();

            res.push_back(vertex + 'a');
            
            for (auto nei: adj[vertex]) {
                if (--indegrees[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        return res.size() == indegrees.size() ? res : "";
    }
};
