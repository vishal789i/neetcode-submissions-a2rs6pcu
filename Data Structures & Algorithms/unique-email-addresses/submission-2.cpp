class Solution {
public:
    string getCleanedStr(string& e) {
        int i = 0;
        while (i < e.size()) {
            if (e[i] == '.') {
                e.erase(e.begin() + i);
            } else if (e[i] == '+') {
                int j = i + 1;
                while (j < e.size() and e[j] != '@') {
                    j++;
                }

                e.erase(i, j - i);
                return e;
            }
            
            i++;
        }

        return e;
    }

    int numUniqueEmails(vector<string>& emails) {
        set<string> st;   
        for (auto& e : emails) {
            st.insert(getCleanedStr(e));
        }

        return st.size();
    }
};