class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<int>visited(points.size(),0);
        int totalCost=0;
        while(!pq.empty())
        {
            auto [cost, node]= pq.top();
            pq.pop();
            if(visited[node])
                continue;
            visited[node]=1;
            totalCost+=cost;
            for(int i =0;i<points.size();i++)
            {
                if(!visited[i])
                {
                    int dist = abs(points[i][0]-points[node][0]) +  abs(points[i][1]-points[node][1]);
                    pq.push({dist,i});
                }
            }
        }
        return totalCost;
    }
};
