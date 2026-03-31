class Solution {
public:
    double dfs(double x, int n) {
        if (x == 0) {
            return 0;
        }

        if (n == 0 or x == 1) {
            return 1;
        }

        if (n % 2 == 0) {
            return dfs(x, n/2) * dfs(x, n/2);
        } else {
            return x * dfs(x, n - 1);
        }
    }

    double myPow(double x, int n) {
        if (n < 0) {
            return dfs(1/x, abs(n));
        }
        
        return dfs(x, n);
    }
};
