class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergedVec;
        for (int i = 0; i < nums1.size(); ++i) {
            mergedVec.push_back(nums1[i]);
        }
        
        for (int i = 0; i < nums2.size(); ++i) {
            mergedVec.push_back(nums2[i]);
        }

        sort(mergedVec.begin(), mergedVec.end());
        
        int n = mergedVec.size();
        int mid = n / 2;
        if (n % 2 == 0) {
            return (mergedVec[mid-1] + mergedVec[mid])/2.0;
        } else {
            return mergedVec[mid];
        }
    }
};
