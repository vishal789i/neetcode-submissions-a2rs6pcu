class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;
        for (auto& d : details) {
            int i = 0;
            while (i < d.size() and isdigit(d[i])) {
                i++;
            }

            // d[i] is not num
            i++;
            int age = (d[i] - '0') * 10 + (d[i + 1] - '0');
            if (age > 60) {
                res++;
            }
        }

        return res;
    }
};