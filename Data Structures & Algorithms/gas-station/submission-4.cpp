    class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int curGas = 0, totalGas = 0, n = gas.size(), res = 0;
            for (int i = 0; i < n; ++i) {
                auto gain = gas[i] - cost[i];
                totalGas += gain;
                curGas += gain;
                if (curGas < 0) {
                    curGas = 0;
                    res = i + 1;
                }
            }

            if (totalGas >= 0) {
                return res;
            }

            return -1;
        }
    };
