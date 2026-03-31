class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res{{1}};
        for (int r = 1; r < numRows; ++r) {
            vector<int> temp{1};
            auto& back = res.back();
            for (int c = 1; c < r; ++c) {
                temp.push_back(back[c - 1] + back[c]);
            }

            temp.push_back(1);
            res.push_back(temp);
        }

        return res;
    }
};