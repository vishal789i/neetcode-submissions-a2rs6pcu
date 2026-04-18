class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        function<pair<int, string>(int)> dfs = [&] (int i) -> pair<int, string> {
            string res;
            int num = 0;
            while (i < s.size()) {
                if (isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                } else if (isalpha(s[i])) {
                    res += s[i];
                    i++;
                } else if (s[i] == '[') {
                    auto [nextIdx, str] = dfs(i + 1);
                    while (num--) {
                        res.append(str);
                    }

                    num = 0;
                    i = nextIdx;
                } else if (s[i] == ']') {
                    return {i + 1, res};
                }
            }

            return {i, res};
        };

        auto [_, res] = dfs(0);
        return res;
    }
};