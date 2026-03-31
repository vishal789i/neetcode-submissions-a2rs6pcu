class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        map<int, int> num2Ngr;
        for (int i = nums2.size() - 1; i >= 0; --i) {
            while (not stk.empty() and stk.top() <= nums2[i]) {
                stk.pop();
            }

            // top > nums[i]
            if (stk.empty()) {
                num2Ngr[nums2[i]] = -1;
            } else {
                num2Ngr[nums2[i]] = stk.top();
            }

            stk.push(nums2[i]);
        }

        vector<int> res;
        for (int i = 0; i < nums1.size(); ++i) {
            res.push_back(num2Ngr[nums1[i]]);
        }

        return res;
    }
};