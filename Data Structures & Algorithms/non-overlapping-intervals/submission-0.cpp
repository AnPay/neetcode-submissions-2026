bool mycompare(const vector<int> a, const vector<int> b)
{
    if(a[1]==b[1])
        return a[0]<b[0];
    return a[1]<b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),mycompare);
        int count=0;
        int prevEnd = intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<prevEnd)
                count++;
            else
                prevEnd = intervals[i][1];
        }    
        return count;
    }
};
/*
1,2  1,4  2,4
*/
