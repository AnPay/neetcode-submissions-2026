class Solution {
public:
    int rows;
    int cols;
    vector<vector<bool>>visited;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int maxarea=0;
        visited = vector<vector<bool>>(rows,vector<bool>(cols,0));
        for(int i =0;i<rows;i++)
        {
            for(int j =0;j<cols;j++)
            {
                if(!visited[i][j] && grid[i][j]==1)
                {
                    int area = bfs(i,j,grid);
                    maxarea = max(area,maxarea);
                }
            }
        }        
        return maxarea;
    }
private:
    int xdir[4]={0,1,0,-1};
    int ydir[4]={1,0,-1,0};
    bool isValid(int r, int c)
    {
        return (r>=0 && c>=0 && r<rows && c<cols);
    }
    int bfs(int r, int c,vector<vector<int>>& grid)
    {
        queue<pair<int,int>> q;
        q.push({r,c});
        visited[r][c]=1;
        int count=0;
       // cout<<"f\n";
        while(!q.empty())
        {
            int cr = q.front().first;
            int cc = q.front().second;
            q.pop();
            count++;
          //  cout<<cr<<" "<<cc<<" "<<count<<"\n";
            for(int i=0;i<4;i++)
            {
                int nr = cr+xdir[i];
                int nc = cc+ydir[i];
                if(isValid(nr,nc) && !visited[nr][nc] && grid[nr][nc]==1)
                {
                    visited[nr][nc]=1;
                    q.push({nr,nc});
                    
                }
            }
        }
        return count;
    }
};
