class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> temp;
        function<void(int)> dfs = [&] (int i) {
            if (i == n) {
                res.push_back(temp);
                return;
            }

            // include
            temp.push_back(nums[i]);
            dfs(i + 1);
            temp.pop_back();

            while ((i + 1) < n and nums[i] == nums[i + 1]) {
                i++;
            }

            dfs(i + 1);
        };

        sort(nums.begin(), nums.end());
        dfs(0);
        return res;
    }
};
