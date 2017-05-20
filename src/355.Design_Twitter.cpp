class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() : time(0) {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //min heap
        follow(userId, userId);
        for (auto users : friends[userId]) {
            for (auto t : tweets[users]) {
                pq.push({t.first, t.second});
                if (pq.size() > 10)
                    pq.pop();//pop the smallest one
            }
        }
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return vector<int> (res.rbegin(), res.rend());
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
    }
    
    unordered_map<int, set<int>> friends; //.second, all the ids that I follow
    unordered_map<int, vector<pair<int, int>>> tweets; //user, {time, tweetId}
    
    int time;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
