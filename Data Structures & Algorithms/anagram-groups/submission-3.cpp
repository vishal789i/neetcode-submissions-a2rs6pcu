class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashMap;
        for (string& str : strs) {
            vector<int> count(26, 0);
            for (char ch : str)
                count[ch - 'a'] += 1;

            string hash = "";
            for (int i = 0; i < count.size(); ++i) {
                hash += '#' + to_string(count[i]);
            }

            hashMap[hash].push_back(str);
        }
        vector<vector<string>> res;
        for (auto& entry : hashMap) {
            res.push_back(vector<string>());
            for (auto& str : entry.second) {
                res.back().push_back(str);
            }
        }
        return res;
    }
};
