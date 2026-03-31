class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        while (i < abbr.size()) {
            if (abbr[i] == '0') {
                return false;
            } else {
                if (isdigit(abbr[i])) {
                    int num = 0;
                    while (isdigit(abbr[i])) {
                        num = num * 10 + (abbr[i] - '0');
                        i++;
                    }

                    // num = 3;
                    j += num;
                } else {
                    if (abbr[i] != word[j]) {
                        return false;
                    }
                    
                    i++;
                    j++;
                }
            }
        }

        return j == word.size();
    }
};

// a p p l e   a 3 e
// 0 1 2 3 4   0 1 2
//         j       i