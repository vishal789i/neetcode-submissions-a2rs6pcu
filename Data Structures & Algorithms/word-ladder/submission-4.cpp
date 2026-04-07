class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while (not q.empty()) {
            auto [word, steps] = q.front();
            q.pop();
            if (word == endWord) {
                return steps;
            }

            for (int i = 0; i < word.size(); ++i) {
                auto originalChar = word[i];
                for (auto ch = 'a'; ch <= 'z'; ++ch) {
                    word[i] = ch;
                    if (wordSet.contains(word)) {
                        wordSet.erase(word);
                        q.push({word, steps + 1});
                    }
                }

                word[i] = originalChar;
            }
        }

        return 0;
    }
};