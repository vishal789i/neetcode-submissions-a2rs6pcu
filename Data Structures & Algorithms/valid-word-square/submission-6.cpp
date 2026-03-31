class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int ROWS = words.size();
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < words[r].size(); ++c) {
                if (c >= ROWS or r >= words[c].size()) { // check if the word at the col as row idx is valid
                    return false;
                }

                if (words[r][c] != words[c][r]) {
                    return false;
                }
            }
        }

        return true;
    }
};
