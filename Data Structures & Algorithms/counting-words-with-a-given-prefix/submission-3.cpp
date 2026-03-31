class Solution {
public:
    struct Node {
        bool isEnd = false;
        vector<Node*> chars{26};
        int wordCnt = 0;
    };
    
    int prefixCount(vector<string>& words, string pref) {
        Node* root = new Node();
        for (auto w : words) {
            auto cur = root;
            for (auto ch : w) {
                if (cur->chars[ch - 'a'] == nullptr) {
                    cur->chars[ch - 'a'] = new Node();
                }

                cur = cur->chars[ch - 'a'];
                cur->wordCnt++;
            }

            cur->isEnd = true;
        }

        auto cur = root;
        for (auto ch : pref) {
            if (cur->chars[ch - 'a'] == nullptr) {
                return 0;
            }

            cur = cur->chars[ch - 'a'];
        }

        return cur->wordCnt;
    }
};