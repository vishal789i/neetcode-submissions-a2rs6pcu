class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> op(n * 2, 0);
        for (int i = 0; i < n * 2; ++i) {
            op[i] = nums[i % n];
        }

        return op;
    }
};
