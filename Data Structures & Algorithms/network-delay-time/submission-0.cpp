class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adjlist(n+1);
        for(auto& vec: times)
        {
            adjlist[vec[0]].push_back({vec[1],vec[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int>dis(n+1,INT_MAX);
        dis[k]=0;
        pq.push({0,k});
        while(!pq.empty())
        {
            int cost = pq.top().first;
            int src = pq.top().second;
            pq.pop();
            //if (cost > dis[src]) continue;

            for(int i =0;i<adjlist[src].size();i++)
            {
                int dst = adjlist[src][i].first;
                int time = adjlist[src][i].second;
                if(dis[dst]>(cost+time))
                {
                    dis[dst]=cost+time;
                    pq.push({dis[dst],dst});
                }
            }
        }    
        int res =0;
        for(int i=1;i<dis.size();i++)
        {
            if(dis[i]==INT_MAX)
                return -1;
            res=max(res,dis[i]);
        }
        return res;
    }
};
