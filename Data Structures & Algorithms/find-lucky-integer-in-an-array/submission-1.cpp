class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> counts(501);
        for (auto a : arr) {
            counts[a]++;
        }

        int res = -1;
        for (int i = 0; i < counts.size(); ++i) {
            if (counts[i] > 0 and counts[i] == i) {
                res = i;
            }
        }

        return res;
    }
};