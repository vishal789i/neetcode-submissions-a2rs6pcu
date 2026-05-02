class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        char prev = '#';
        int res = 1, l = 0, r = 1;
        while (r < arr.size()) {
            if (arr[r - 1] > arr[r] and prev != '>') {
                prev = '>';
                res = max(res, r - l + 1);
                r++;
            } else if (arr[r - 1] < arr[r] and prev != '<') {
                prev = '<';
                res = max(res, r - l + 1);
                r++;
            } else {
                if (arr[r - 1] == arr[r]) {
                    r++;
                }

                l = r - 1;
                prev = '#';
            }
        }

        return res;
    }
};