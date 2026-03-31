class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> st;   
        for (auto& e : emails) {
            string local = "";
            int i = 0;
            while (i < e.size() and e[i] != '+' and e[i] != '@') {
                if (e[i] != '.') {
                    local.push_back(e[i]);
                }

                i++;
            }

            // '+' or '@'
            while (i < e.size() and e[i] != '@') {
                i++;
            }

            // '@'
            string domain = "";
            i++;
            while (i < e.size()) {
                domain.push_back(e[i++]);
            }

            st.insert(local + '@' + domain);
        }

        return st.size();
    }
};