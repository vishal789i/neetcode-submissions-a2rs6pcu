class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int l = 0;
        deque<int> dq;
        for (int r = 0; r < nums.size(); ++r) {
            while (not dq.empty() and dq.back() < nums[r]) {
                dq.pop_back();
            }

            dq.push_back(nums[r]);
            if (r - l + 1 == k) {
                res.push_back(dq.front());
                if (not dq.empty() and dq.front() == nums[l]) {
                    dq.pop_front();
                }

                l++;
            }
        }

        return res;
    }
};
