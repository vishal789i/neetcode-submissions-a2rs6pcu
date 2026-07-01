class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") {
            return 0;
        }

        unordered_set<string> vis(deadends.begin(), deadends.end());
        if (vis.contains("0000")) {
            return -1;
        }

        int res = 0;
        queue<string> q;
        q.push("0000");
        while (not q.empty()) {
            res++;
            int size = q.size();
            while (size--) {
                auto cur = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    for (auto move : {-1, 1}) {
                        auto next = cur;
                        next[i] = ((next[i] - '0') + move + 10) % 10 + '0';
                        if (vis.contains(next)) {
                            continue;
                        }

                        if (next == target) {
                            return res;
                        }

                        vis.insert(next);
                        q.push(next);
                    }
                }
            }
        }

        return -1;
    }
};