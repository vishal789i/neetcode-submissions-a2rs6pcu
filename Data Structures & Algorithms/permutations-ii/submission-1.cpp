class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int, int> num2Cnt;
        for (auto n : nums) {
            num2Cnt[n]++;
        }
        
        vector<vector<int>> res;
        vector<int> op;
        function<void(void)> dfs = [&] () {
            if (op.size() == nums.size()) {
                res.push_back(op);
                return;
            }

            for (auto& [num, cnt] : num2Cnt) {
                if (cnt == 0) {
                    continue;
                }

                op.push_back(num);
                cnt--;
                dfs();
                op.pop_back();
                cnt++;
            }
        };

        dfs();
        return res;

    }
};