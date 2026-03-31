class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;
        for (string& d : details) {
            int i = 0;
            while (i < d.size() and isdigit(d[i])) {
                i++;
            }

            i++; // gender
            int age = 0;
            age = (d[i] - '0') * 10 + (d[i + 1] - '0');
            if (age > 60) {
                res++;
            }
        }

        return res;
    }
};