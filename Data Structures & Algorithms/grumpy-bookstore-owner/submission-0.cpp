class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int l = 0, r = 0;
        int satisfied = 0;
        int window = 0;
        int maxWindow = 0;
        while (r < customers.size()) {
            if (grumpy[r] == 1) {
                window += customers[r];
            } else {
                satisfied += customers[r];
            }

            if (r - l + 1 > minutes) {
                if (grumpy[l] == 1) {
                    window -= customers[l];
                }

                l++;
            }
            
            maxWindow = max(maxWindow, window);
            r++;
        }

        return satisfied + maxWindow;
    }
};