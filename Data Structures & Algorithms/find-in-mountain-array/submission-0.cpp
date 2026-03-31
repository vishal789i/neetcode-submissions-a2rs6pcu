/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len = mountainArr.length();
        int l = 0, r = len - 1;
        int peak = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            int midLeft = mountainArr.get(m - 1), mid = mountainArr.get(m), midRight = mountainArr.get(m + 1);
            if (midLeft < mid and mid < midRight) {
                l = m + 1;
            } else if (midLeft > mid and mid > midRight) {
                r = m - 1;
            } else {
                peak = m;
                break;
            }
        }

        l = 0, r = peak;
        while (l <= r) {
            int m = (l + r) / 2;
            int mid = mountainArr.get(m);
            if (target == mid) {
                return m;
            }
            
            if (target > mid) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        l = peak, r = len - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            int mid = mountainArr.get(m);
            if (target == mid) {
                return m;
            }
            
            if (target > mid) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return -1;
    }
};