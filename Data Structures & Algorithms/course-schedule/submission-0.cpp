class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses,0);
        for(int i =0;i<prerequisites.size();i++)
        {
            //for(int j =0;j<prerequisites[i].size();j++)
            {
                indegree[prerequisites[i][1]]++;
                graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
            }
        }
        queue<int>q;
        for(int i =0;i<numCourses;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        int finish=0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            finish++;
            for(int nei : graph[node])
            {
                indegree[nei]--;
                if(indegree[nei]==0)
                    q.push(nei);
            }
        }
        return finish == numCourses;
    }
};
