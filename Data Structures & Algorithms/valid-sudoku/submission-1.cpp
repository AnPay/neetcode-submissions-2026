class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
     //check each row
     //check each column
     //check each 3x3 block
     return isRowValid(board) && isColValid(board) && isBlockValid(board);   
    }
private:
    bool isRowValid(vector<vector<char>>& board)
    {
        for(int i =0;i<9;i++)
        {
            unordered_set<char> hash;
            for(int j =0;j<9;j++)
            {
                char item = board[i][j];
                if(item!='.' && hash.count(item)>0)
                    return false;
                hash.insert(item);
            }
        }
        return true;
    }

    bool isColValid(vector<vector<char>>& board)
    {
        for(int i =0;i<9;i++)
        {
            unordered_set<char> hash;
            for(int j =0;j<9;j++)
            {
                char item = board[j][i];
                if(item!= '.' && hash.count(item)>0)
                    return false;
                hash.insert(item);
            }
        }
        return true;
    }
    bool isBlockValid(vector<vector<char>>& board)
    {
        for(int sq =0;sq<9;sq++)
        {
            unordered_set<char> hash;
            for(int i =0;i<3;i++)
            {
                for(int j =0;j<3;j++)
                {
                    int row = (sq/3)*3+i;
                    int col = (sq%3)*3+j;
                    char item = board[row][col];
                    if(item!= '.' && hash.count(item)>0)
                        return false;
                    hash.insert(item);

                }
            }
        }
        return true;
    }
};
