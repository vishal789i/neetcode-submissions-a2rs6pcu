class Solution {
    int getSumOfSquares(int num) {
        int res = 0;
        while (num) {
            res += pow(num % 10, 2);
            num = num / 10;
        }
        return res;
    }

public:
    bool isHappy(int num) {
        set<int> st;
        while (num != 1 and not st.count(num)) {
            st.insert(num);
            num = getSumOfSquares(num);
        }

        return num == 1;
    }
};
