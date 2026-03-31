class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res;
        for (int i = 0; i < temperatures.size(); ++i) {
            int j = i + 1, count = 1;
            while (j < temperatures.size()) {
                if (temperatures[j] > temperatures[i]) {
                    res.push_back(count);
                    break;
                }
                ++j;
                ++count;
            }
            if (j == temperatures.size()) {
                res.push_back(0);
            }
        }
        return res;
    }
};
