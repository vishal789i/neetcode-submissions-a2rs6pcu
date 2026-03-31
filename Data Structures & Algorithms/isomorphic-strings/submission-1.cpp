class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        map<char, int> mp;
        for (int i = 0; i < s.size(); ++i) {
            if (not mp.contains(s[i])) {
                mp[s[i]] = t[i];
            } else {
                if (mp[s[i]] != t[i]) {
                    return false;
                }
            }
        }

        mp.clear();

        swap(s, t);
        for (int i = 0; i < s.size(); ++i) {
            if (not mp.contains(s[i])) {
                mp[s[i]] = t[i];
            } else {
                if (mp[s[i]] != t[i]) {
                    return false;
                }
            }
        }

        return true;
    }
};