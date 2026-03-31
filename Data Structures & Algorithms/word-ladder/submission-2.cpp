class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> dict(wordList.begin(), wordList.end());
        int res = 1;
        queue<string> q;
        q.push(beginWord);

        while (not q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                auto word = q.front();
                q.pop();
                
                if (word == endWord) {
                    return res;
                }

                dict.erase(word);
                
                for (int j = 0; j < word.size(); ++j) {
                    auto temp = word[j];
                    for (char k = 'a'; k <= 'z'; ++k) {
                        word[j] = k;
                        if (dict.count(word)) {
                            q.push(word);
                        }
                    }
                    word[j] = temp;
                }
            }
            res++;
        }

        return 0;
    }
};