class Solution {
public:
    string encode(vector<string>& strs) {
        string res;
        for (auto& s : strs) {
            res += to_string(s.size()) + '#' + s;
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            string lenStr = "";
            while (s[i] != '#') {
                lenStr += s[i++];
            }

            int len = stoi(lenStr);
            i++;
            string word = "";
            while (len--) {
                word += s[i++];
            }

            res.push_back(word);
        }

        return res;
    }
};
