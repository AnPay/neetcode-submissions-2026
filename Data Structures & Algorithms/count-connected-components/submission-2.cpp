class unionFind{
   
    public:
         vector<int>parent;
        unionFind(int size){
        parent.resize(size);
        for(int i =0;i<size;i++)
            parent[i]=i;
        }
    
    int find(int n)
    {
        if(n == parent[n])
            return n;
        return find(parent[n]);
    }
    bool unionf(int n1, int n2)
    {
        int p1 = find(n1);
        int p2 = find(n2);
        // cout<<n1<<" "<<n2<<"\n";
        // cout<<"parent of "<<n1<<"is "<<p1<<"\n";
        // cout<<"parent of "<<n2<<"is "<<p2<<"\n";
        if(p1!=p2)
            {
                parent[p2]=p1;
                // cout<<"Modifying\n";
                // cout<<"parent of "<<n1<<"is "<<p1<<"\n";
                //  cout<<"parent of "<<n2<<"is "<<p1<<"\n";
                return 1;
            }
        return 0;
    }
    };
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unionFind uf(n);
        int results=n;
        for( auto ed :edges)
        {
            if(uf.unionf(ed[0],ed[1])==1)
                {
                    
                    results--;
                    // for(int i=0;i<n;i++)
                    // {
                    //     cout<<"parent of "<<i<<"is "<<uf.parent[i]<<"\n";
                    // }
                }
        }
        return results;
        
    }
};
