class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> maxHeap;
        if (a) maxHeap.push({a, 'a'});
        if (b) maxHeap.push({b, 'b'});
        if (c) maxHeap.push({c, 'c'});
        string res = "";
        while (not maxHeap.empty()) {
            auto [f, ch] = maxHeap.top();
            maxHeap.pop();
            if (res.size() > 1 and res[res.size() - 1] == ch and res[res.size() - 2] == ch) {
                if (maxHeap.empty()) break;
                auto [f2, ch2] = maxHeap.top();
                maxHeap.pop();
                f2--;
                maxHeap.push({f, ch});
                if (f2) maxHeap.push({f2, ch2});
                res.push_back(ch2);
            } else {
                res.push_back(ch);
                --f;
                if (f > 0) maxHeap.push({f, ch});
            }
        }

        return res;
    }
};