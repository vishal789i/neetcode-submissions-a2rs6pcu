class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0, res = 0;
        map<int, int> mp;
        for (int r = 0; r < fruits.size(); ++r) {
            mp[fruits[r]]++;
            while (mp.size() > 2) {
                if (--mp[fruits[l]] == 0) {
                    mp.erase(fruits[l]);
                }

                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};