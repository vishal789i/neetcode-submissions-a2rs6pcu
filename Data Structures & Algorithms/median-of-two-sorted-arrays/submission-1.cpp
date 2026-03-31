class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1;
        vector<int>& B = nums2;

        if (A.size() > B.size()) swap(A, B);

        int n = A.size();
        int m = B.size();
        int total = n + m;
        int half = total / 2;

        int l = 0, r = n;
        while (l <= r) {
            int i = (l + r) / 2;
            int j = half - i;

            int Aleft = (i > 0) ? A[i - 1] : INT_MIN;
            int Aright = (i < n) ? A[i] : INT_MAX;
            int Bleft = (j > 0) ? B[j - 1] : INT_MIN;
            int Bright = (j < m) ? B[j] : INT_MAX;

            if (Aleft <= Bright && Bleft <= Aright) {
                if (total % 2 == 0) {
                    return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
                } else {
                    return min(Aright, Bright);  // ✅ Only change needed
                }
            } else if (Aleft > Bright) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }

        return -1; // Unreachable if inputs are valid
    }
};
