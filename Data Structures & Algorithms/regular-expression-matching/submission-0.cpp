class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.size() == 0) {
            return s.size() == 0;
        }

        auto isFirstCharMatching = s.size() > 0 and (s[0] == p[0] or p[0] == '.');
        if (p[1] == '*') {
            auto notTake = isMatch(s, p.substr(2));
            auto take = isFirstCharMatching and isMatch(s.substr(1), p);
            return notTake or take;
        } else {
            return isFirstCharMatching and isMatch(s.substr(1), p.substr(1));
        }
    }
};
