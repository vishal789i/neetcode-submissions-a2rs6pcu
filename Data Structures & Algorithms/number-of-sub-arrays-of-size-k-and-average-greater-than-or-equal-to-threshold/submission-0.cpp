class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int l = 0, r = 0, res = 0, sum = 0;
        while (r < arr.size()) {
            sum += arr[r];
            if (r - l + 1 == k) {
                if (sum / k >= threshold) {
                    res++;
                }

                sum -= arr[l];
                l++;
            }

            r++;
        }

        return res;
    }
};