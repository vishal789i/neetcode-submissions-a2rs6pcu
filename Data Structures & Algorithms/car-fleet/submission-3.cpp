class Solution {
public:
    int carFleet(int target, vector<int>& positions, vector<int>& speeds) {
        vector<pair<int, int>> posSpeedPairVec(positions.size());
        for (int i = 0; i < positions.size(); ++i) {
            posSpeedPairVec[i].first = positions[i];
            posSpeedPairVec[i].second = speeds[i];
        }

        sort(posSpeedPairVec.begin(), posSpeedPairVec.end(), [] (auto& pairA, auto& pairB) {
            return pairA.first > pairB.first;
        });

        vector<double> stk; // time 
        for (auto& posSpeedPair : posSpeedPairVec) {
            int pos = posSpeedPair.first, speed = posSpeedPair.second;
            double timeToReach = (target - pos) / ( speed * 1.0 ); // for double precision division
            stk.push_back(timeToReach);
            if (stk.size() >= 2 and stk[stk.size()-1] <= stk[stk.size()-2]) {
                stk.pop_back();
            }
        }
        return stk.size();
    }
};
