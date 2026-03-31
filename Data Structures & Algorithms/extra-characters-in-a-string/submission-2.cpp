class Solution {
    struct Node {
        bool isWord{false};
        vector<Node*> chars{26};
    };

    Node* root;

public:
    int minExtraChar(string s, vector<string>& dictionary) {
        root = new Node();
        for (auto& word : dictionary) {
            auto cur = root;
            for (auto ch : word) {
                if (cur->chars[ch - 'a'] == nullptr) {
                    cur->chars[ch - 'a'] = new Node();
                }

                cur = cur->chars[ch - 'a'];
            }

            cur->isWord = true;
        }

        function<int(int)> dfs = [&] (int i) {
            if (i == s.size()) {
                return 0;
            }

            auto cur = root;
            int res = 1 + dfs(i + 1);
            for (int j = i; j < s.size(); ++j) {
                if (cur->chars[s[j] - 'a'] == nullptr) {
                    break;
                }

                cur = cur->chars[s[j] - 'a'];
                if (cur->isWord) {
                    res = min(res, dfs(j + 1));
                }
            }

            return res;
        };

        return dfs(0);
    }
};