class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0, el1 = 0, el2 = 1;
        for (auto num : nums) {
            if (el1 == num) {
                cnt1++;
            } else if (el2 == num) {
                cnt2++;
            } else if (cnt1 == 0) {
                el1 = num;
                cnt1 = 1;
            } else if (cnt2 == 0) {
                el2 = num;
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = cnt2 = 0;
        for (auto num : nums) {
            if (num == el1) {
                cnt1++;
            } else if (num == el2) {
                cnt2++;
            }
        }

        vector<int> res;
        int mini = (nums.size() / 3) + 1;
        if (cnt1 >= mini) {
            res.push_back(el1);
        }

        if (cnt2 >= mini) {
            res.push_back(el2);
        }

        return res;
    }
};