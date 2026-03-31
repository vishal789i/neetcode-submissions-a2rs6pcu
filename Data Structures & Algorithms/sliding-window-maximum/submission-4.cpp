class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0, r = 0, maxEle = INT_MIN;
        deque<int> dq;
        vector<int> maxEleVec;
        while (r < nums.size()) {
            while (not dq.empty() and dq.back() < nums[r]) {
                dq.pop_back();
            }

            dq.push_back(nums[r]);

            if (r - l + 1 == k) {
                maxEleVec.push_back(dq.front());

                if (not dq.empty() and dq.front() == nums[l]) {
                    dq.pop_front();
                }

                l++;
            }
            
            r++;
        }

        return maxEleVec;
    }
};
