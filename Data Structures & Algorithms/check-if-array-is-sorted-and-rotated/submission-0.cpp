class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int minIdx = -1;
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] > nums[i]) {
                minIdx = i;
                break;
            }
        }

        if (minIdx == -1) {
            return true;
        }

        for (int i = 0; i < n - 1; ++i) {
            if (nums[(i + minIdx) % n] > nums[(i + minIdx + 1) % n]) {
                return false;
            }
        }

        return true;
    }
};
/*
B[3, 4, 5, 1, 2]
 0  1  2  3  4

A 1  2  3  4  5
A[0] == B[3] == B[(0 + 3) % 5]

1 1 1 1 1 1 2


*/