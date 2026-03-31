class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, vector<string>> hashKey2AnagramGroups;
        for (std::string& str: strs) {
            vector<int> freqVec(26, 0);
            for (char ch: str) {
                freqVec[ch - 'a']++;
            }

            std::string hashKey;
            for (int freq: freqVec) {
                hashKey += '#' + freq;
            }
            
            hashKey2AnagramGroups[hashKey].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto [_, anagramGroups]: hashKey2AnagramGroups) {
            ans.push_back(anagramGroups);
        }

        return ans;
    }
};
