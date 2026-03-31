class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> vis(deadends.begin(), deadends.end());
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
                auto lock = q.front();
                q.pop();
                for (int i = 0; i < lock.size(); ++i) {
                    for (int move : {1, -1}) {
                        auto digit = lock[i] - '0';
                        auto nextLock = lock;
                        nextLock[i] = ((digit + move + 10) % 10) + '0';
                        if (vis.contains(nextLock)) {
                            continue;
                        }

                        if (nextLock == target) {
                            return res;
                        }

                        q.push(nextLock);
                        vis.insert(nextLock);
                    }
                }
            }
        }

        return -1;
    }
};