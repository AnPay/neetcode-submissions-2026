class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> candidates;
        vector<bool> pick(nums.size(),0);
        backtrack(nums,candidates,res,pick);
        return res;    
    }
private:
    void backtrack(vector<int>& nums, vector<int>& candidates,
    vector<vector<int>> &res,vector<bool> &pick)
    {
        if(candidates.size()==nums.size())
        {
            res.push_back(candidates);
            return;
        }
        for(int i =0;i<nums.size();i++)
        {
            if(pick[i]==0){
                candidates.push_back(nums[i]);
                pick[i]=1;
                backtrack(nums,candidates,res,pick);
                candidates.pop_back();
                pick[i]=0;
            }
        }

    }
};
