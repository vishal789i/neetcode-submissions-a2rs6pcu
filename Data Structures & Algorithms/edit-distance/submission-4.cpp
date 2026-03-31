class Solution {
public:
    int minDistance(string word1, string word2) {
        int M = word1.size(), N = word2.size();
        function<int(int, int)>  dfs = [&] (int i, int j) {
            if (i == M) {
                return N - j;
            }

            if (j == N) {
                return M - i;
            }
            
            if (word1[i] == word2[j]) {
                return dfs(i + 1, j + 1);
            }

            return 1 + min({dfs(i, j + 1), dfs(i + 1, j), dfs(i + 1, j + 1)});
        };

        return dfs(0, 0);
    }
};
