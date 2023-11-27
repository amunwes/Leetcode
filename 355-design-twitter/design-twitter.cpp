class Twitter {
public:
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        int count = 10;
        int n = tweets.size();
        for(int i=n-1; i>=0; i--){
            if (count==0){
                break;
            }
            int followId = tweets[i].first;
            int tweetId = tweets[i].second;
            if(following[userId].find(followId) != following[userId].end() || followId == userId){
                result.push_back(tweetId);
                count--;
            }

        }

        return result;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
private:
    vector<pair<int,int>> tweets;
    unordered_map<int,unordered_set<int>> following;
    
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */