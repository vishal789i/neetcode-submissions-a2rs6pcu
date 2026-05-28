class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        int l = 0;
        for (int r = 0; r < nums.size(); ++r) {
            while (not dq.empty() and dq.back() < nums[r]) {
                dq.pop_back();
            }

            dq.push_back(nums[r]);
            if (r - l + 1 == k) {
                res.push_back(dq.front());
                if (dq.front() == nums[l]) {
                    dq.pop_front();
                }

                l++;
            }
        }

        return res;
    }
};
