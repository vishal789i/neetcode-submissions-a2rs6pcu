class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        set<int> s(nums.begin(), nums.end());
        int res = 1;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (s.count(num - 1)) {
                continue;
            }

            int len = 1;
            while (s.count(num + 1)) {
                len++;
                num++;
            }

            res = max(res, len);
        }

        return res;
    }
};
