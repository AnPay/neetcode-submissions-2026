class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int>candidates;
        set<vector<int>> res;
        sort(nums.begin(),nums.end());
        backtrack(nums,target,candidates,res,0);    
        return vector<vector<int>>(res.begin(),res.end());    
    }
private:
    void backtrack(vector<int>& nums, int target, vector<int>& candidates,set<vector<int>> &res, int i)
    {
        if(target==0)
        {
            res.insert(candidates);
            return;
        }
        if(target<0 || i>=nums.size())
            return;
        //if(candidates.find(nums[i])==candidates.end())
        //if(find(candidates.begin(),candidates.end(),nums[i])==candidates.end())
        {
            candidates.push_back(nums[i]);
            backtrack(nums,target-nums[i],candidates,res,i+1);
            candidates.pop_back();
            backtrack(nums,target,candidates,res,i+1);
        }
    }
};
