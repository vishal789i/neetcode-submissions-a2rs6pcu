class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> hash2StrVec;
        for (auto str : strs) {
            vector<char> freqVec(26, 0);
            for (auto ch : str) {
                freqVec[ch - 'a'] += 1;
            }
            
            std::string hash = "";
            for (auto freq : freqVec) {
                hash += to_string(freq) + "$";
            }

            hash2StrVec[hash].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto [hash, strVec] : hash2StrVec) {
            ans.push_back(vector<string>());
            for (auto str : strVec) {
                ans.back().push_back(str);
            }
        }

        return ans;
    }
};
