class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        vector<int> ngrs(nums2.size());
        for (int i = nums2.size() - 1; i >= 0; --i) {
            while (not stk.empty() and stk.top() <= nums2[i]) {
                stk.pop();
            }

            // top > nums[i]
            if (stk.empty()) {
                ngrs[i] = -1;
            } else {
                ngrs[i] = stk.top();
            }

            stk.push(nums2[i]);
        }

        vector<int> res;
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                if (nums1[i] == nums2[j]) {
                    res.push_back(ngrs[j]);
                }
            }
        }

        return res;
    }
};