class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        for (auto& s : strs) {
            vector<int> freqs(26, 0);
            for (auto ch : s) {
                freqs[ch - 'a'] ++;
            }

            std::string hash = "";
            for (auto f : freqs) {
                hash.append(to_string(f) + '#');
            }

            mp[hash].push_back(s);
        }

        vector<vector<string>> res;
        for (auto [ignore, group] : mp) {
            res.push_back(group);
        }

        return res;
    }
};
