class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;

        int N = flowerbed.size();

        for (int i = 0; i < N && n > 0; ++i) {
            if (flowerbed[i] != 0) continue;

            int left = (i > 0) ? flowerbed[i - 1] : 0;
            int right = (i < N - 1) ? flowerbed[i + 1] : 0;

            if (left == 0 && right == 0) {
                flowerbed[i] = 1;
                n--;
            }
        }

        return n == 0;
    }
};
