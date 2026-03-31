class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        set<int> res;
        for (auto triplet : triplets) {
            if (triplet[0] > target[0] or triplet[1] > target[1] or triplet[2] > target[2]) {
                continue;
            }

            for (int i = 0; i < 3; ++i) {
                if (triplet[i] == target[i]) {
                    res.insert(i);
                }
            }
        }

        return res.size() == 3;
    }
};
