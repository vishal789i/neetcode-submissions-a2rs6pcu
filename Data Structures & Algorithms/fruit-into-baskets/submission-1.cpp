class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int, int> mp;
        int res = 0;
        for (int l = 0, r = 0; r < fruits.size(); ++r) {
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