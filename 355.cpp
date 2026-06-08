class Twitter {
private:
    int timestamp = 0;
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> following;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

        if (!tweets[userId].empty()) {
            auto& t = tweets[userId].back();
            pq.push({t.first, t.second, (int)tweets[userId].size() - 1, userId});
        }

        for (const auto& followeeId : following[userId]) {
            if (!tweets[followeeId].empty()) {
                auto& t = tweets[followeeId].back();
                pq.push({t.first, t.second, (int)tweets[followeeId].size() - 1, followeeId});
            }
        }

        vector<int> feed;
        while (!pq.empty() && feed.size() < 10) {
            auto item = pq.top(); pq.pop();
            int tweetId = item[1];
            feed.push_back(tweetId);

            int ts = item[0];
            int idx = item[2];
            int followeeId = item[3];
            if (idx > 0) {
                auto& nextTweet = tweets[followeeId][idx - 1];
                pq.push({nextTweet.first, nextTweet.second, idx - 1, followeeId});
            } 
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

