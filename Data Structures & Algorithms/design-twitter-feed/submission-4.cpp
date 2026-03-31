class Twitter {
    using Time = int;
    Time m_Time = 0;
    map<int, set<int>> userId2Followees; // user follows whom
    map<int, vector<pair<int, Time>>> userId2TweetIdTimePairs;

public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        userId2TweetIdTimePairs[userId].push_back({tweetId, m_Time++});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<Time, int>, vector<pair<Time, int>>, greater<>> minHeap;
        for (auto [tweetId, time] : userId2TweetIdTimePairs[userId]) {
            minHeap.push({time, tweetId});
            if (minHeap.size() > 10) {
                minHeap.pop();
            }
        }

        for (auto& followeeId : userId2Followees[userId]) {
            for (auto [tweetId, time] : userId2TweetIdTimePairs[followeeId]) {
                minHeap.push({time, tweetId});
                if (minHeap.size() > 10) {
                    minHeap.pop();
                }
            }
        }
        
        vector<int> res;
        while (not minHeap.empty()) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }

        userId2Followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }
        
        userId2Followees[followerId].erase(followeeId);
    }
};
