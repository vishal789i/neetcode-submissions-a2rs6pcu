class NumArray {
    vector<int> sums;
    // 0, -2, 
public:
    NumArray(vector<int>& nums) {
        sums.push_back(0);
        int cur = 0;
        for (auto n : nums) {
            cur += n;
            sums.push_back(cur);
        }
    }
    
    int sumRange(int left, int right) {
        return sums[right + 1] - sums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */