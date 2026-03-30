class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    set<vector<int>>res;
    vector<int>candidates={};
    sort(nums.begin(),nums.end());
    backtrack(nums,candidates,res,0);
    vector<vector<int>> res2;
    return vector<vector<int>>(res.begin(),res.end());    
    }
private:
    void backtrack(vector<int>& nums, vector<int>& candidates,set<vector<int>>&res, int i )
    {
        res.insert(candidates);
        if(i==nums.size())
        {
            res.insert(candidates);
            return;
        }
        for(int idx =i;idx<nums.size();idx++)
        {
            candidates.push_back(nums[idx]);
            backtrack(nums,candidates,res,idx+1);
            candidates.pop_back();
        } 
    }
};
