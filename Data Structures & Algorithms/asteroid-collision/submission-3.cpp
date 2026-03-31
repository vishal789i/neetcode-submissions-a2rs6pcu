class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;
        for (auto& a : asteroids) {
            while (not stk.empty() and a < 0 and stk.back() > 0) {
                auto diff = stk.back() + a;
                if (diff < 0) {
                    stk.pop_back();
                } else if (diff > 0) {
                    a = 0;
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