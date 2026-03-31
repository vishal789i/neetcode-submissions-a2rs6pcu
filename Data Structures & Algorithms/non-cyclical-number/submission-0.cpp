class Solution {
public:
    bool isHappy(int n) {
        set<int> st;
        int res = 0;
        int num = n;
        while (true) {
            res = 0;
            while (num) {
                res += pow(num % 10, 2);
                num = num / 10;
            }

            if (res == 1) {
                return true;
            } else {
                if (st.count(res)) {
                    return false;
                }
                st.insert(res);
                num = res;
            }
        }

        return false;
    }
};
