class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        res.push_back(intervals[0]);
        for(int i =1;i<intervals.size();i++)
        {
            if(intervals[i][0]<=res.back()[1])
            {
                //overlap->merge
                res.back()[1]=max(res.back()[1],intervals[i][1]);
            }  
            else //no overlap, insert
            res.push_back(intervals[i]);  

        }    
        return res;
    }
};
/*
Pattern: Interval merging
Transition: Sort intervals based on start_i
for all intervals:
    if(end[i]>start[i+1])
        merge(i,i+1)
    else 
        i++
*/