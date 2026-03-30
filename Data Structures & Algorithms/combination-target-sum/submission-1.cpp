class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>candidates;
        vector<vector<int>> res;
        backtrack(nums,target,candidates,res,0);    
        return res;
    }
private:
    void backtrack(vector<int>& nums, int target, vector<int>& candidates,vector<vector<int>> &res, int i)
    {
        if(target==0)
        {
            res.push_back(candidates);
            return;
        }
        if(target<0 || i>=nums.size())
            return;
        candidates.push_back(nums[i]);
        backtrack(nums,target-nums[i],candidates,res,i);
        candidates.pop_back();
        backtrack(nums,target,candidates,res,i+1);
    }
};
