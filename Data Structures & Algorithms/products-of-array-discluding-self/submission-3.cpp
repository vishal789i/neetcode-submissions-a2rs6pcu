class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> prefixVec(nums.size(), 1);
        int prefix = 1;
        for (int i=0; i<nums.size(); ++i) {
            prefixVec[i] = prefix;
            prefix *= nums[i];
        }
        
        std::vector<int> postfixVec(nums.size(), 1);
        int postfix = 1;
        for (int i=nums.size()-1; i>=0; --i) {
            postfixVec[i] = postfix;
            postfix *= nums[i];
        }

        std::vector<int> resultVec(nums.size(), 1);
        for (int i=0; i<nums.size(); ++i) {
            resultVec[i] = prefixVec[i] * postfixVec[i];
        }

        return resultVec;
    }
};
