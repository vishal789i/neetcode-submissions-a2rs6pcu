class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> lastIdx;
        for (int i = 0; i < s.size(); ++i) {
            lastIdx[s[i]] = i;
        }

        vector<int> res;
        int end = 0, size = 0;
        for (int i = 0; i < s.size(); ++i) {
            size++;
            end = max(end, lastIdx[s[i]]);
            int j = 0;
            if (i == end) {
                res.push_back(size);
                size = 0;
            }
        }

        return res;
    }
};
