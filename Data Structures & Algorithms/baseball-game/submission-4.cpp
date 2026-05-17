class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> stk;
        for (auto& o : operations) {
            if (o == "+") {
                stk.push_back(stk[stk.size() - 1] + stk[stk.size() - 2]);
            } else if (o == "C") {
                stk.pop_back();
            } else if (o == "D") {
                stk.push_back(stk[stk.size() - 1] * 2);
            } else {
                stk.push_back(stoi(o));
            }
        }

        return accumulate(stk.begin(), stk.end(), 0);
    }
};