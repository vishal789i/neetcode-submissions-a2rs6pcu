class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> ch2Freq;
        for (auto c : s) {
            ch2Freq[c]++;
        }

        priority_queue<pair<int, char>> maxHeap;
        for (auto [ch, freq] : ch2Freq) {
            maxHeap.push({freq, ch});
        }

        string res = "";
        pair<int, char> prev = {0, ' '};
        while (not maxHeap.empty() or prev.first > 0) {
            if (prev.first > 0 and maxHeap.empty()) {
                return "";
            }

            auto [f, ch] = maxHeap.top();
            maxHeap.pop();
            res.push_back(ch);
            f--;
            if (prev.first > 0) {
                maxHeap.push(prev);
            }

            prev = {f, ch};
        }

        return res;
    }
};