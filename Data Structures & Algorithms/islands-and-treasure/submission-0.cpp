class Solution {
public:
    int rows;
    int cols;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        for(int i =0;i<rows;i++)
        {
            for(int j =0;j<cols;j++)
            {
                if(grid[i][j]==2147483647)
                {
                    grid[i][j]=bfs(i,j,grid);
                }
            }
        }
    }
private:
    int xdir[4]={0,1,0,-1};
    int ydir[4]={1,0,-1,0};
    int bfs(int r, int c,vector<vector<int>>& grid )
    {
        vector<vector<bool>> visited(rows,vector<bool>(cols,0));
        queue<pair<int,int>>q;
        q.push({r,c});
        visited[r][c]=1;
        int count=0;
        while(!q.empty())
        {
            int size = q.size();
            
            for(int s =0;s<size;s++)
            {
                int cr = q.front().first;
                int cc = q.front().second;
                q.pop();
                
                if(grid[cr][cc]==0)
                    return count;
                for(int i =0;i<4;i++)
                {
                    int nr = cr+xdir[i];
                    int nc = cc+ydir[i];
                    if(nr>=0 &&nc>=0 && nr<rows&& nc<cols && grid[nr][nc]!=-1)
                    {
                        if(!visited[nr][nc])
                        {
                            q.push({nr,nc});
                            visited[nr][nc]=1;
                        }
                        
                    }
                }
            }
            count++;
        }
        return 2147483647;
    }
};
