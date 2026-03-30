class Twitter {
public:
    unordered_map<int,vector<pair<int,int>>>userIdToTweetId;
    unordered_map<int,unordered_set<int>>userIdToFollowId;
    int globaltime;
    Twitter() {
        userIdToTweetId.clear();
        userIdToFollowId.clear();
        globaltime=0;
    }
    
    void postTweet(int userId, int tweetId) {
        if(userIdToTweetId.find(userId)!=userIdToTweetId.end())
            userIdToTweetId[userId].push_back({globaltime++,tweetId});
        else
            userIdToTweetId.insert({userId, {{globaltime++,tweetId}}});
        
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>maxHeap;
        vector<pair<int,int>> usertweets;
        if(userIdToTweetId.find(userId)!=userIdToTweetId.end())
            usertweets =userIdToTweetId[userId];
        for( auto item : usertweets)
            maxHeap.push(item);
        if(userIdToFollowId.find(userId)!=userIdToFollowId.end())
        {
            for(auto id :userIdToFollowId[userId] )
            {
                for(auto tid :userIdToTweetId[id] )
                    maxHeap.push(tid);
            }
        }
        vector<int>res;
        int count=10;
        while(!maxHeap.empty() && count>0)
        {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
            count--;
        }
        return res;

    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        userIdToFollowId[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        // if(userIdToFollowId.find(followeeId)!=userIdToFollowId.end())
        // {
        //     vector<int> followers = userIdToFollowId[followeeId];
        //     auto it = find(followers.begin(),followers.end(),followerId);
            
        // } 
        
        if(userIdToFollowId.find(followerId)!=userIdToFollowId.end())
        {
            cout<<"delete\n";
            auto &s = userIdToFollowId[followerId];
            s.erase(followeeId);
        }   
        
    }
};
