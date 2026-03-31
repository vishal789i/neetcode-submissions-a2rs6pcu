class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string, int> counts;
        for (auto& s : arr) {
            counts[s]++;
        }

        for (auto& s : arr) {
            if (counts[s] == 1) {
                k--;
                if (k == 0) {
                    return s;
                }
            }
        }

        return "";
    }
};