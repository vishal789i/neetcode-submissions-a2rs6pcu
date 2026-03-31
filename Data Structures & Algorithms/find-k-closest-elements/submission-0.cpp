class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            int da = abs(a - x), db = abs(b - x);
            if (da == db) return a < b; // tie-breaker: smaller value
            return da < db;
        });

        vector<int> res(arr.begin(), arr.begin() + k);
        sort(res.begin(), res.end()); // result must be in ascending order
        return res;
    }
};
