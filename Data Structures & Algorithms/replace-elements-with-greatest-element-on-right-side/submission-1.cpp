class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            int rightMax = -1;
            for (int j = i + 1; j < n; ++j) {
                rightMax = max(rightMax, arr[j]);
            }
            res[i] = rightMax;
        }
        return res;
    }
};