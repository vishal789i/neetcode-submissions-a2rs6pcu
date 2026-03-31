class Solution {
public:
    vector<int> getNSRVec(vector<int>& heightsVec) {
        int pseudoIdx = heightsVec.size();
        stack<pair<int, int>> stk;
        vector<int> res;
        for (int i = heightsVec.size() - 1; i >= 0; --i) {
            while (not stk.empty() and stk.top().first >= heightsVec[i]) {
                stk.pop();
            }

            if (stk.empty()) {
                res.push_back(pseudoIdx);
            } else {
                res.push_back(stk.top().second);
            }

            stk.push({heightsVec[i], i});
        }

        reverse(res.begin(), res.end());

        return res;
    }

    vector<int> getNSLVec(vector<int>& heightsVec) {
        int pseudoIdx = -1;
        stack<pair<int, int>> stk;
        vector<int> res;
        for (int i = 0; i < heightsVec.size(); ++i) {
            while (not stk.empty() and stk.top().first >= heightsVec[i]) {
                stk.pop();
            }

            if (stk.empty()) {
                res.push_back(pseudoIdx);
            } else {
                res.push_back(stk.top().second);
            }

            stk.push({heightsVec[i], i});
        }
        
        return res;
    }

    int largestRectangleArea(vector<int>& heightsVec) {
        auto leftVec = getNSLVec(heightsVec);
        auto rightVec = getNSRVec(heightsVec);

        vector<int> areaVec(heightsVec.size(), 0);
        for (int i = 0; i < areaVec.size(); ++i) {
            areaVec[i] = heightsVec[i] * (rightVec[i] - leftVec[i] - 1);
        }

        return *max_element(areaVec.begin(), areaVec.end());
    }
};
