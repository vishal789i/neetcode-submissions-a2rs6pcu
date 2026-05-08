class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> res;
        for (auto& q : queries) {
            int minLen = INT_MAX;
            for (auto& i : intervals) {
                auto s = i[0], e = i[1], l = e - s + 1;
                if (s <= q and q <= e) {
                    minLen = min(minLen, l);
                }
            }

            res.push_back(minLen == INT_MAX ? -1 : minLen);
        }

        return res;
    }
};
