class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector prev(amount + 1, 0), cur(amount + 1, 0);
        for (int amt = 0; amt <= amount; ++amt) {
            prev[amt] = amt % coins[0] == 0 ? 1 : 0;
        }

        for (int i = 1; i < coins.size(); ++i) {
            for (int amt = 0; amt <= amount; ++amt) {
                auto notTake = prev[amt];
                auto take = 0;
                if (coins[i] <= amt) {
                    take = cur[amt - coins[i]];
                }

                cur[amt] = take + notTake;
            }

            prev = cur;
        }

        return prev[amount];
    }
};
