class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftProds(n, 1), rightProds(n, 1), res(n);
        for (int i = 1; i < n; ++i) {
            leftProds[i] *= leftProds[i - 1] * nums[i - 1];
        }

        for (int i = n - 2; i >= 0; --i) {
            rightProds[i] *= rightProds[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; ++i) {
            res[i] = leftProds[i] * rightProds[i];
        }

        return res;
    }
};
