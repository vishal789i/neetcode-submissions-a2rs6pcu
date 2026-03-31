class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> positives;
        for (auto num : nums) {
            if (num > 0) {
                positives.insert(num);
            }
        }

        int target = 1;
        for (auto num : positives) {
            if (num == target) {
                target++;
            } else {
                return target;
            }
        }

        return target;
    }
};