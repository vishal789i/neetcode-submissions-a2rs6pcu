class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> s;
        for (auto n : nums) {
            if (s.find(n) != s.end()) {
                return true;
            }

            s.insert(n);
        }

        return false;
    }
};