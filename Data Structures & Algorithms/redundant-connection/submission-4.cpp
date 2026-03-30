class unionFind{
public:
    vector<int>parent;
    unionFind(int n)
    {
        parent.resize(n);
        for(int i =0;i<n;i++)
            parent[i]=i;
    }
    int findParent(int n)
    {
        if(parent[n]==n)
            return n;
        return findParent(parent[n]);
    }
    bool unionSet(int n1, int n2)
    {
        int p1 = findParent(n1);
        int p2 = findParent(n2);
       // cout<<n1<<" "<<n2<<" "<<p1<<" "<<p2<<"\n";
        if(p1==p2)
            return 1;
        
        parent[p2]=p1;
        return 0;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        unionFind uf(n+1);
        for(auto ed : edges)
        {
            int isRedund = uf.unionSet(ed[0],ed[1]);
            if(isRedund)
                return ed;
        }
        return {};
    }
};
