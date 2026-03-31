class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> counts(nums.size());
        for (auto n : nums) {
            counts[n - 1]++;
        }
        
        // 1 2 2 1 0 0 1 1
        // 1 2 3 4 5 6 7 8
        vector<int> res;
        for (int i = 0; i < counts.size(); ++i) {
            if (counts[i] == 0) {
                res.push_back(i + 1);
            }
        }

        return res;
    }
};