class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::vector<int> countsS1(26);
        std::vector<int> countsS2(26);

        for (int i = 0; i < s1.length(); ++i) {
            countsS1[s1[i] - 'a']++;
            countsS2[s2[i] - 'a']++;
        }

        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (countsS1[i] == countsS2[i]) {
                matches++;
            }
        }

        int l = 0, r = s1.length();
        while (r < s2.length()) {
            if (matches == 26) {
                return true;
            }
            
            int index = s2[r] - 'a';
            countsS2[index]++;
            if (countsS1[index] == countsS2[index]) {
                matches++;
            } else if (countsS1[index] + 1 == countsS2[index]) {
                matches--;
            }
            r++;
            
            index = s2[l] - 'a';
            countsS2[index]--;
            if (countsS1[index] == countsS2[index]) {
                matches++;
            } else if (countsS1[index] - 1 == countsS2[index]) {
                matches--;
            }

            l++;
        }

        return matches == 26;
    }
};
