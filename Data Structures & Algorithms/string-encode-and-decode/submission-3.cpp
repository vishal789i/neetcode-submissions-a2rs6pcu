class Solution {
public:
    string encode(vector<string>& strs) {
        string res;
        for (auto& str: strs) {
            res += to_string(str.size()) + "#" + str;
        }
        return res;
    }

    vector<string> decode(string str) {
        vector<string> res;
        int i = 0;
        while (i < str.size()) {
            int j = i;
            while (str[j] != '#') {
                j++;
            }

            // now str[j] == '#'        
            auto len = stoi(str.substr(i, j - i));
            i = j + 1;
            res.push_back(str.substr(i, len));
            i += len;
        }
        return res;
    }
};
