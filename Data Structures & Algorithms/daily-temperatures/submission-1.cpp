class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res;
        for (int i = 0; i < temperatures.size(); ++i) {
            int j = i + 1;
            while (j < temperatures.size()) {
                if (temperatures[j] > temperatures[i]) {
                    res.push_back(j - i);
                    break;
                }
                ++j;
            }
            if (j == temperatures.size()) {
                res.push_back(0);
            }
        }
        return res;
    }
};
