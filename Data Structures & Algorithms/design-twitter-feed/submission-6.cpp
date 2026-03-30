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
        priority_queue<tuple<int,int,int,int>>maxHeap;
        userIdToFollowId[userId].insert(userId);
        for(int followee: userIdToFollowId[userId])
        {
            auto &tweets = userIdToTweetId[followee];
            if(!tweets.empty()) 
            {
                int idx = userIdToTweetId[followee].size()-1;
                maxHeap.push({tweets[idx].first,tweets[idx].second,followee,idx});
            }
        }
        vector<int>res;
        while(!maxHeap.empty()&&res.size()<10)
        {
            auto [time, tweetId, uid, idx] = maxHeap.top();
            res.push_back(tweetId);
            maxHeap.pop();
            if(idx>0)
                maxHeap.push({userIdToTweetId[uid][idx-1].first,
                             userIdToTweetId[uid][idx-1].second,
                             uid,idx-1});
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
