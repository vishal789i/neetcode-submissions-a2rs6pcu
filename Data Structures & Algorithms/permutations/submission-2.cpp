class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> temp;
        function<void(int)> dfs = [&] (int i) {
            if (i == n) {
                res.push_back(temp);
                return;
            }

            for (int j = 0; j < n; ++j) {
                if (find(temp.begin(), temp.end(), nums[j]) == temp.end()) {
                    temp.push_back(nums[j]);
                    dfs(i + 1);
                    temp.pop_back();
                }
            }
        };

        dfs(0);
        return res;
    }
};
