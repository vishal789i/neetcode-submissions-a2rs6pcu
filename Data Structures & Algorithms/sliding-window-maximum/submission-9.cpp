class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        int l = 0, r = 0, n = nums.size();
        while (r < n) {
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
            
            r++;
        }

        return res;
    }
};
