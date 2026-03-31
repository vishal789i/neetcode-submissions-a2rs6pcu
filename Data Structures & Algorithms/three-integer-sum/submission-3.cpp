class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] and i > 0) continue;
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum > 0) {
                    r--;
                } else if (sum < 0) {
                    l++;
                } else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    
                    while (nums[l] == nums[l-1] and l < r) {
                        l++;
                    }

                    while (nums[r] == nums[r+1] and l < r) {
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};
