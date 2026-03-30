class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>order(numCourses);
        vector<int> indegree(numCourses,0);
        vector<vector<int>>adj(numCourses);    
        for(int i =0;i<prerequisites.size();i++)
        {
            indegree[prerequisites[i][1]]++;
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        display(adj);
        for(int n : indegree)
        {
            cout<<n<<"\n";
        }
        queue<int>q;
        for(int i =0;i<numCourses;i++)
        {
            if(indegree[i]==0)
               {
                cout<<"Pushing"<<i<<"\n";
                 q.push(i);
               }
        }
        int finish=0;
        while(!q.empty())
        {
            int node = q.front();
            order[numCourses - finish - 1] = node;
            finish++;
            cout<<"In order"<<node<<"\n";
            q.pop();
            //order.push_back(node);
            for(int nei : adj[node])
            {
                indegree[nei]--;
                if(indegree[nei]==0)
                    q.push(nei);
            }
        }
        if(finish==numCourses)
            return order;
        else
            return {};
    }
private:
    void display(vector<vector<int>>& graph)
    {
        for(auto n: graph)
        {
            for( int a : n)
                cout<<a<<" ";
            cout<<"\n";
        }
    }
};
