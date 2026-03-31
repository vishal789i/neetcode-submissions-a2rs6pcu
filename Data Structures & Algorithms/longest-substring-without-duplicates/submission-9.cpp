class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int res = 0;
        for (auto r = 0, l = 0; r < s.size(); ++r) {
            while (st.count(s[r])) {
                st.erase(s[l]);
                l++;
            }

            res = max(res, r - l + 1);
            st.insert(s[r]);
        }
        return res;
    }
};
