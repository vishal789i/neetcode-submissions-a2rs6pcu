class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0, el1 = 0, el2 = 0;
        for (auto n : nums) {
            if (el1 == n) {
                cnt1++;
            } else if (el2 == n) {
                cnt2++;
            } else if (cnt1 == 0) {
                el1 = n;
                cnt1++;
            } else if (cnt2 == 0) {
                el2 = n;
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0, cnt2 = 0;
        for (auto n : nums) {
            if (n == el1) {
                cnt1++;
            } else if (n == el2) {
                cnt2++;
            }
        }

        int mini = nums.size() / 3;
        vector<int> res;
        if (cnt1 > mini) {
            res.push_back(el1);
        }

        if (cnt2 > mini) {
            res.push_back(el2);
        }

        return res;
    }
};