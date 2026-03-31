class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);
        int rightMax = -1;
        for (int i = n - 1; i >= 0; --i) {
            res[i] = rightMax;
            rightMax = max(rightMax, arr[i]);
        }

        return res;
    }
};