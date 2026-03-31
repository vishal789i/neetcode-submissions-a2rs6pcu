class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) {
            return true;
        }

        int N = flowerbed.size();
        for (int i = 0; i < N; ++i) {
            if (flowerbed[i] != 0) {
                continue;
            }

            int left = i > 0 ? flowerbed[i - 1] : 0;
            int right = i < N - 1 ? flowerbed[i + 1] : 0;
            if (left == 0 and right == 0) {
                flowerbed[i] = 1;
                n--;
                if (n == 0) {
                    break;
                }
            }
        }

        return n == 0;
    }
};