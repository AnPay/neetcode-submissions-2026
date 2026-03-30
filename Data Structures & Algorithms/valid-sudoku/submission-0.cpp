class Solution {
public:
    bool isRowValid(vector<vector<char>>& board)
    {
        for(int i =0;i<9;i++)
        {
            unordered_set<char>HT;
            for(int j =0;j<9;j++)
            {
                if(board[i][j]=='.')
                    continue;
                if(HT.count(board[i][j]))
                   {cout<<"here"; return false;}
                HT.insert(board[i][j]);
            }

        }
        return true;
    }
    bool isColumnValid(vector<vector<char>>& board)
    {
        for(int col =0;col<9;col++)
        {
            unordered_set<char>HT;
            for(int j =0;j<9;j++)
            {
                if(board[j][col]=='.')
                    continue;
                if(HT.count(board[j][col]))
                    {cout<<"hereCol"; return false;}
                HT.insert(board[j][col]);
            }

        }
        return true;
    }
    bool isGridValid(vector<vector<char>>& board)
    {
        for(int sq =0;sq<9;sq++)
        {
            unordered_set<char>HT;
            for(int i =0;i<3;i++)
            {
                for(int j =0;j<3;j++)
                {
                    int row = (sq/3)*3+i;
                    int col = (sq%3)*3+j;
                    if(board[row][col]=='.')
                        continue;
                    if(HT.count(board[row][col]))
                        {cout<<"hereG"<<row<<col ;return false;}
                    HT.insert(board[row][col]);
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return (isRowValid(board) && isColumnValid(board) && isGridValid(board));
    }
};
