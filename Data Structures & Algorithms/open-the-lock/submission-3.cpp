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
            auto size = q.size();
            for (int level = 0; level < size; ++level) {
                string lock = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    for (int move : {-1, 1}) {
                        auto nextLock = lock;
                        nextLock[i] = (((nextLock[i] - '0') + 10 + move) % 10) + '0';
                        if (nextLock == target) {
                            return res;
                        }

                        if (not deadends.contains(nextLock)) {
                            deadends.insert(nextLock);
                            q.push(nextLock);
                        }
                    }
                }
            }
        }

        return -1;
    }
};