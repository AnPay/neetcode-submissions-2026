class Solution {
public:
    vector<vector<bool>> visited;
    int rows,cols;
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int count=0;
        visited = vector<vector<bool>>(rows,vector<bool>(cols,0));
        for(int i =0;i<rows;i++)
        {
            for(int j =0;j<cols;j++)
            {
                if(!visited[i][j] && grid[i][j]=='1')
                {
                    bfs(i,j,grid);
                    count++;
                }
            }
        }        
        return count;
    }
private:
    int xdir[4]={0,1,0,-1};
    int ydir[4]={1,0,-1,0};
    bool isValid(int r, int c)
    {
        return (r>=0 && c>=0 && r<rows && c<cols);
    }
    void bfs(int r, int c,vector<vector<char>>& grid)
    {
        queue<pair<int,int>> q;
        q.push({r,c});
        while(!q.empty())
        {
            int cr = q.front().first;
            int cc = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr = cr+xdir[i];
                int nc = cc+ydir[i];
                if(isValid(nr,nc) && !visited[nr][nc] && grid[nr][nc]=='1')
                {
                    visited[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
    }
};
