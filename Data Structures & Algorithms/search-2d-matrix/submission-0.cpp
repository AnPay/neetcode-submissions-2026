class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int ROWS = matrix.size();
       int COLS = matrix[0].size();
       int lo = 0;
       int hi = ROWS-1;
       while(lo<=hi)
       {
            int mid = lo +(hi-lo)/2;
            if(target>matrix[mid][COLS-1])  //checking if more than that row
                lo=mid+1;
            else if(target < matrix[mid][0])  //checking if less than that row
                hi=mid-1;
            else
                break;  //row found
       } 
       if(lo>hi)
        return false;

        int row = (lo+hi)/2;  //recomputing found row, can be avoided by storing the row in a temp var
        int l=0,r=COLS-1;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(target > matrix[row][mid])
                l=mid+1;
            else if(target < matrix[row][mid])
                r=mid-1;
            else
                return true;
        }
        return false;
    }
};
