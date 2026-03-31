class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& ip, vector<int>& op) {
        if (ip.empty()) {
            ans.push_back(op);
            return;
        }

        int temp = ip.back();
        ip.pop_back();
        op.push_back(temp);
        solve(ip, op);
        op.pop_back();
        ip.push_back(temp);

        ip.pop_back();
        solve(ip, op);
        ip.push_back(temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> op;
        solve(nums, op);
        return ans;
    }
};
