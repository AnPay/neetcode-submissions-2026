class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>candidates;
        vector<vector<int>>res;
        backtrack(nums,candidates,res,0);
        return res;    
    }
private:
    void backtrack(vector<int>& nums,vector<int> &candidates,vector<vector<int>> &res, int i)
    {
        if(i==nums.size())
        {
            res.push_back(candidates);
            return;
        }
        candidates.push_back(nums[i]);
        backtrack(nums,candidates,res,i+1);
        candidates.pop_back();
        backtrack(nums,candidates,res,i+1);
    }
};
