class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;

        // Stack will hold: {index, current_sum, current_combination}
        stack<tuple<int, int, vector<int>>> st;
        st.push({0, 0, {}});

        while (!st.empty()) {
            auto [idx, curSum, temp] = st.top();
            st.pop();

            if (curSum == target) {
                res.push_back(temp);
                continue;
            }

            // Try all numbers from idx onwards
            for (int i = idx; i < nums.size(); ++i) {
                if (curSum + nums[i] <= target) {
                    auto next = temp;
                    next.push_back(nums[i]);
                    st.push({i, curSum + nums[i], move(next)}); 
                    // use i (not i+1) because we can reuse nums[i]
                }
            }
        }

        return res;
    }
};
