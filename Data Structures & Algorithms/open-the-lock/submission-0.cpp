class Solution {
public:
    vector<string> getChildren(string& lock) {
        vector<string> res;
        for (int i = 0; i < lock.size(); ++i) {
            int digit = lock[i] - '0';
            auto next = lock;
            next[i] = ((digit + 1) % 10) + '0';
            res.push_back(next);
            next[i] = ((digit - 1 + 10) % 10) + '0';
            res.push_back(next);
        }

        return res;
    }

    int openLock(vector<string>& deadends, string target) {
        if (find(deadends.begin(), deadends.end(), "0000") != deadends.end()) {
            return -1;
        }

        set<string> vis(deadends.begin(), deadends.end());
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        while (not q.empty()) {
            auto [lock, count] = q.front();
            q.pop();
            if (lock == target) {
                return count;
            }

            for (auto child : getChildren(lock)) {
                if (not vis.contains(child)) {
                    vis.insert(child);
                    q.push({child, count + 1});
                }
            }
        }

        return -1;
    }
};