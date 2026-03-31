class Solution {
public:

    string encode(vector<string>& strs) {
        std::string ansStr;
        for (auto& str: strs) {
            ansStr += std::to_string(str.size()) + '#' + str;
        }
        return ansStr;
    }

    vector<string> decode(string s) {
        int i = 0;
        std::vector<std::string> ansVec;
        while (i < s.size()) {
            int j = i;
            
            while(s[j] != '#') {
                j++;
            }

            int length = std::stoi(s.substr(i, j-i));
            std::string word = s.substr(j+1, length);
            ansVec.push_back(word);
            i = length + j + 1;
        }
        return ansVec;
    }
};
