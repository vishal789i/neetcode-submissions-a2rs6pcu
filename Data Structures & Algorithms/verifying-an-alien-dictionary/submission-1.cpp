class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> order2Idx;
        for (auto i = 0; i < order.size(); ++i) {
            order2Idx[order[i]] = i;
        }

        for (int i = 0; i < words.size() - 1; ++i) {
            auto w1 = words[i], w2 = words[i + 1];
            for (int j = 0; j < w1.size(); ++j) {
                if (j == w2.size()) {
                    return false;
                }

                if (w1[j] != w2[j]) {
                    if (order2Idx[w1[j]] > order2Idx[w2[j]]) {
                        return false;
                    }

                    break;
                }
            }
        }

        return true;
    }
};