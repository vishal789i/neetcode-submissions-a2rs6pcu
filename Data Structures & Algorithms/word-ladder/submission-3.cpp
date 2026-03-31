class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, vector<string>> wordHash2WordListMap;
        for (auto word: wordList) {
            for (int j = 0; j < word.size(); ++j) {
                auto wordHash = word.substr(0, j) + "*" + word.substr(j + 1);
                wordHash2WordListMap[wordHash].push_back(word);
            }
        }

        int res = 1;
        queue<string> q;
        q.push(beginWord);
        set<string> vis;

        while (not q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                auto word = q.front();
                q.pop();
                
                if (word == endWord) {
                    return res;
                }
                
                for (int j = 0; j < word.size(); ++j) {
                    auto wordHash = word.substr(0, j) + "*" + word.substr(j + 1);
                    for (auto adjWord: wordHash2WordListMap[wordHash]) {
                        if (vis.count(adjWord)) {
                            continue;
                        }
                        
                        q.push(adjWord);
                        vis.insert(adjWord);
                    }
                }
            }
            res++;
        }

        return 0;
    }
};