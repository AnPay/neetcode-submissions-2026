class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(int start, int target, vector<int> &state, vector<int> &nums)
    {
        if(target ==0)
        {
            ans.push_back(state);
            return;
        }
        //prune invalid path
        if(target<0)
            return;
        //possible choices
        for(int i =start;i<nums.size();i++)
        {
            //make choice(state,choice)
            state.push_back(nums[i]);
            backtrack(i,target-nums[i],state,nums);
            state.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<int> state;
        backtrack(0,target,state,nums);
        return ans;   
    }
};
/*
backtrace(state):
    if solution:
        save
        return
    for each choice:
        make choice
        backtrack
        undo choice

state = (current combination, remaining target, start index)
*/