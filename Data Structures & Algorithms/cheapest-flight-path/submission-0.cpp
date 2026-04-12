class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adjlist(n);
        for(auto& vec: flights)
        {
            adjlist[vec[0]].push_back({vec[1],vec[2]});
        }

        priority_queue<tuple<int,int, int>, vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        
        vector<int> minhops(n,INT_MAX);
        
        minhops[src]=0;
        pq.push({0,src,0});  //cost,dst,hops
        while(!pq.empty())
        {
            auto [cost, node, stops] = pq.top();
            pq.pop();
            if (node == dst) return cost;

            if(stops>k) continue;

            if(stops > minhops[node]) continue;
            minhops[node]=stops;

            for(int i =0;i<adjlist[node].size();i++)
            {
                int dst = adjlist[node][i].first;
                int price = adjlist[node][i].second;
               // if(dis[dst]>(cost+time))
                {
                    
                    pq.push({cost+price,dst,stops+1});
                }
            }
        }   
        return -1;     
    }
};
