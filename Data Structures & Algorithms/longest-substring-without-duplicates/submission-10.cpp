class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        set<char> st;
        int res = 0;
        for (int r = 0; r < s.size(); ++r) {
            while (st.contains(s[r])) {
                st.erase(s[l]);
                l++;
            }

            st.insert(s[r]);
            res = max(res, r - l + 1);
        }

        return res;
    }
};
