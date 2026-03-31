class Solution {
public:
    int count(int n) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            if (n % 2 != 0) {
                res++;
            }

            n = n >> 1;
        }

        return res;
    }

    vector<int> countBits(int n) {
        vector<int> res;
        for (int num = 0; num <= n; ++num) {
            res.push_back(count(num));
        }

        return res;
    }
};
