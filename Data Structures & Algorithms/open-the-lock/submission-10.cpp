class Solution {
public:
    int openLock(vector<string>& deadend, string target) {
        set<string> deadends(deadend.begin(), deadend.end());
        if (deadends.contains("0000")) {
            return -1;
        }

        queue<string> q;
        q.push("0000");
        int res = 0;
        while (not q.empty()) {
            res++;
            int size = q.size();
            while (size--) {
                auto lock = q.front();
                q.pop();
                for (auto i = 0; i < lock.size(); ++i) {
                    for (auto move : {-1, 1}) {
                        auto nextLock = lock;
                        nextLock[i] = (((nextLock[i] - '0') + move + 10) % 10) + '0';
                        if (target == nextLock) {
                            return res;
                        }

                        if (deadends.contains(nextLock)) {
                            continue;
                        }

                        deadends.insert(nextLock);
                        q.push(nextLock);
                    }
                }
            }
        }

        return -1;
    }
};