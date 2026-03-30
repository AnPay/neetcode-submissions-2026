class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n,0);
        for(int i =0;i<prerequisites.size();i++)
        {
            int src = prerequisites[i][1];
            int dest = prerequisites[i][0];
            graph[src].push_back(dest);
            indegree[dest]++;
        }        
        queue<int>q;
        for(int i =0;i<n;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        int finish=0;
        while(!q.empty())
        {
            int n = q.front();
            q.pop();
            finish++;
            for(int nei : graph[n])
            {
                indegree[nei]--;
                if(indegree[nei]==0)
                    q.push(nei);
            }
        }
        return finish==n?1:0;
    }
};
