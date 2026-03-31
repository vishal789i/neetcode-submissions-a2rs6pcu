class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> op;
        function<void(int, vector<int>&)> dfs = [&] (int i, vector<int>& op) {
            if (i == nums.size()) {
                ans.push_back(op);
                return;
            }

            op.push_back(nums[i]);
            dfs(i+1, op);
            op.pop_back();

            dfs(i+1, op);
        };
        
        dfs(0, op);
        return ans;
    }
};
