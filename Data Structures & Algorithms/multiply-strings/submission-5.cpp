class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" or num2 == "0") {
            return "0";
        }

        vector<int> res(num1.size() + num2.size());
        reverse(begin(num1), end(num1));
        reverse(begin(num2), end(num2));
        for (int i = 0; i < num1.size(); ++i) {
            for (int j = 0; j < num2.size(); ++j) {
                auto prod = (num1[i] - '0') * (num2[j] - '0');
                res[i + j] += prod;
                res[i + j + 1] += res[i + j] / 10;
                res[i + j] %= 10;
            }
        }

        // 0100
        reverse(begin(res), end(res));
        int k = 0;
        while (k < res.size() and res[k] == 0) {
            cout << res[k];
            k++;
        }

        string resStr;
        while (k < res.size()) {
            cout << res[k];
            resStr.push_back(res[k] + '0');
            k++;
        }

        return resStr;
    }
};
