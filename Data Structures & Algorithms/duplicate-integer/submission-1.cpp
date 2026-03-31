class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> s;
        for (auto& num: nums) {
            if (s.find(num) != s.end()) {
                return true;
            } else {
                s.insert(num);
            }
        }
        return false;
    }
};
