class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int l = 0;
        vector<int> res;
        for (int r = 0; r < nums.size(); ++r) {
            while (not q.empty() and q.back() < nums[r]) {
                q.pop_back();
            }

            q.push_back(nums[r]);

            if (r - l + 1 == k) {
                res.push_back(q.front());

                if (not q.empty() and q.front() == nums[l]) {
                    q.pop_front();
                }
                l++;
            }
        }
        return res;
    }
};
