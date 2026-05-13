class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> charCnts(26);
        for (auto c : chars) {
            charCnts[c - 'a']++;
        }

        int res = 0;
        for (auto& w : words) {
            vector<int> wCnts(26);
            for (auto c : w) {
                wCnts[c - 'a']++;
            }
            /*
                a 2
                c 1
                h 1
                t 1

                a 1
                c 1
                t 1
            */

            bool match = true;
            for (int i = 0; i < 26; ++i) {
                if (wCnts[i] > charCnts[i]) {
                    match = false;
                    break;
                }
            }

            if (match) {
                res += w.size();
            }
        }

        return res;
    }
};