class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, vector<int>& op, set<int>& vis) {
        if (op.size() == nums.size()) {
            ans.push_back(op);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (vis.find(nums[i]) == vis.end()) {
                vis.insert(nums[i]);
                op.push_back(nums[i]);
                dfs(nums, op, vis);
                op.pop_back();
                vis.erase(nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> op;
        set<int> vis;
        dfs(nums, op, vis);
        return ans;
    }
};
