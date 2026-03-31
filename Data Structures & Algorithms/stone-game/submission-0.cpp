class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        map<pair<int, int>, int> mp;
        function<int(int, int)> dfs = [&] (int l, int r) {
            if (l > r) {
                return 0;
            }

            if (mp.contains({l, r})) {
                return mp[{l, r}];
            }

            auto even = (l - r) % 2 == 0;
            auto left = even ? piles[l] : 0;
            auto right = even ? piles[r] : 0;
            return mp[{l, r}] = max(left + dfs(l + 1, r), right + dfs(l, r - 1));
        };

        auto total = accumulate(piles.begin(), piles.end(), 0);
        auto aliceScore = dfs(0, piles.size() - 1);
        return aliceScore > total - aliceScore;
    }
};