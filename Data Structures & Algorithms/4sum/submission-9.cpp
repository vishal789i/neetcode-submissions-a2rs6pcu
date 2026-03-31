class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n - 3; ++i) {
      if (i > 0 and nums[i - 1] == nums[i]) {
        continue;
      }
      
      for (int j = i + 1; j < n - 2; ++j) {
        if (j > i + 1 and nums[j - 1] == nums[j]) {
          continue;
        }
        
        int k = j + 1, l = n - 1;
        while (k < l) {
          long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
          if (sum < target) {
            k++;
          } else if (sum > target) {
            l--;
          } else {
            res.push_back({nums[i], nums[j], nums[k], nums[l]});
            k++;
            l--;
            while (k < l and nums[k - 1] == nums[k]) {
              k++;
            }
            
            while (k < l and nums[l] == nums[l + 1]) {
              l--;
            }
          }
        }
      }
    }
    
    return res;
  }
};