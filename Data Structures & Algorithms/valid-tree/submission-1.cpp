class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()> n-1)
            return false;

        vector<vector<int>>graph(n);
        for(auto ed : edges)
        {
            int src = ed[0];
            int dest = ed[1];
            graph[src].push_back(dest);
            graph[dest].push_back(src);
        }

        vector<int>visited(n,0);
        // for (int u = 0; u < n; u++)
        // {
        //     if (!visited[u])
        //     {
                if (dfs(graph, visited,0, -1))
                    return false;
        //     }
        // }

        
        for(int v : visited)
        {
            cout<<v<<"\n";
            if(v==0)
                return false;
        }
        return true;
    }
private:
    bool dfs(vector<vector<int>>& graph, vector<int>& visited,int index, int parent){
        visited[index]=1;
        cout<<"index"<<index<<"\n";
        for(auto child: graph[index])
        {
            cout<<"index "<<index<<" child"<<child<<"\n";
            if (!visited[child])
            {
                if (dfs(graph, visited, child,index))
                    return true;
            }
            else if (child != parent)
                return true;
        }
        return false;

    }
};
