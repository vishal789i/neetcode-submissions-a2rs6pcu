class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string temp;
        while (ss >> temp) {
            words.push_back(temp);
        }

        if (pattern.size() != words.size()) {
            return false;
        }

        map<char, string> mp;
        for (int i = 0; i < pattern.size(); ++i) {
            if (not mp.contains(pattern[i])) {
                mp[pattern[i]] = words[i];
            } else {
                if (mp[pattern[i]] != words[i]) {
                    return false;
                }
            }
        }

        map<string, char> mp2;
        for (int i = 0; i < words.size(); ++i) {
            if (not mp2.contains(words[i])) {
                mp2[words[i]] = pattern[i];
            } else {
                if (mp2[words[i]] != pattern[i]) {
                    return false;
                }
            }
        }

        return true;
    }
};