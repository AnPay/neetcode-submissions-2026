class Solution {
public:
    vector<vector<bool>> visited;
    bool exist(vector<vector<char>>& board, string word) {
        
        int rows = board.size();
        int cols = board[0].size();
        int len = word.length();
        visited = vector<vector<bool>>(rows,vector<bool>(cols,false));
        for(int i =0;i<rows;i++)
        {
            for(int j =0;j<cols;j++)
            {
                if(board[i][j]==word[0])
                {
                    cout<<board[i][j]<<"s\n";
                    bool r = dfs(i,j,board,0,word);
                    if(r==1)
                        return 1;
                }
            }
        }
        return 0;
        
    }
private:
    int xdir[4] = {0,1,0,-1};
    int ydir[4] = {1,0,-1,0};
    
    bool dfs(int r, int c, vector<vector<char>>& board,int idx, string word)
    {
        cout<<idx<<" "<<word.length()<<"\n";
        if(idx==word.length())
            return 1;

        if(r<0 || r>=board.size() || c<0 || c>=board[0].size() ||
        visited[r][c] || board[r][c]!=word[idx] )
            return 0;
        
        visited[r][c]=1;
        bool res = dfs(r,c+1,board,idx+1,word) ||
                    dfs(r+1,c,board,idx+1,word) ||
                    dfs(r,c-1,board,idx+1,word) ||
                    dfs(r-1,c,board,idx+1,word);
        visited[r][c]=0;

        return res;
    }
};
