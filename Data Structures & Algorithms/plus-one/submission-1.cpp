class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int i = 0;
        int one = 1;
        while (one) {
            if (i < digits.size()) {
                if (digits[i] == 9) {
                    digits[i] = 0;
                } else {
                    digits[i] += 1;
                    one = 0;
                }
            } else {
                digits.push_back(1);
                one = 0;
            }

            i++;
        }

        reverse(digits.begin(), digits.end());
        return digits;
    }
};