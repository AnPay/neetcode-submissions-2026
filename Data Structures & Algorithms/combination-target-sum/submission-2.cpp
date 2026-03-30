/*
Pattern: BT(choose->explore->unchoose)
State: current candidate, target, start idx
Base: if(target==0) push vec in res, if(target<0) ignore
Transition:
choose nums[i], 
recurse with reduced target, keep i as start to reuse
undo choice

Invariant:
target always represents remaining sum
elements before "start" are already considered
combination only grows forward (avoids permutations)

Complexity:O(2^target)
Edge case:
target = 0 → return [[]]
empty nums → return []
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> candidate;
        bt(nums,target,candidate,0);
        return res;
        
    }
private:
    void bt(vector<int>& nums, int target, vector<int>& cand,int start)
    {
        if(target == 0)
        {
            res.push_back(cand);
            return;
        }
        if(target<0)
            return;
        for(int i=start;i<nums.size();i++)
        {
            cand.push_back(nums[i]);
            bt(nums, target-nums[i],cand,i);
            cand.pop_back();
        }
    }
};
