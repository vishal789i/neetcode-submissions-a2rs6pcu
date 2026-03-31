class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;
        for (auto& a : asteroids) {
            while (not stk.empty() and stk.back() > 0 and a < 0) {
                if (stk.back() > abs(a)) {
                    a = 0;
                } else if (stk.back() < abs(a)) {
                    stk.pop_back();
                } else {
                    a = 0;
                    stk.pop_back();
                }
            }

            if (a != 0) {
                stk.push_back(a);
            }
        }

        return stk;
    }
};