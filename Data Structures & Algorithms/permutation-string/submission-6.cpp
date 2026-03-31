class Solution {
public:
    bool checkPermutation(std::vector<int>& countsS1, std::vector<int>& countsS2) {
        for (int i = 0; i < 26; ++i) {
            if (countsS1[i] != countsS2[i]) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        std::vector<int> countsS1(26);
        std::vector<int> countsS2(26);

        for (int i = 0; i < s1.size(); ++i) {
            countsS1[s1[i] - 'a']++;
        }

        int l = 0, r = 0;
        while (r < s2.size()) {
            countsS2[s2[r] - 'a']++;
            
            if (r - l + 1 != s1.size()) {
                r++;
            } else {
                if (checkPermutation(countsS1, countsS2)) {
                    return true;
                }

                countsS2[s2[l] - 'a']--;
                l++;
                r++;
            }
        }

        return false;
    }
};
