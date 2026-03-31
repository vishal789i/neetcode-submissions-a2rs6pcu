class Solution {
public:
    int lengthOfLastWord(string s) {
        int j = s.size() - 1;
        while (s[j] == ' ') {
            s.pop_back();
            j--;
        }

        int i = 0;
        int startOfWord = -1;
        int endOfWord = 0;
        while (i < s.size()) {
            if (s[i] == ' ') {
                startOfWord = i;
            } else {
                endOfWord = i;
            }

            i++;
        }

        return endOfWord - startOfWord;
    }
};