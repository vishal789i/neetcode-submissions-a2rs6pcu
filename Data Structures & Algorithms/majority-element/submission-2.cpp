class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int el = 0;
        for (auto num : nums) {
            if (num == el) {
                cnt++;
            } else if (cnt == 0) {
                el = num;
                cnt = 1;
            } else {
                cnt--;
            }
        }

        cnt = 0;
        for (auto num : nums) {
            if (el == num) {
                cnt++;
            }
        }

        int mini = (nums.size() / 2) + 1;
        if (cnt >= mini) {
            return el;
        }

        return -1;
    }
};