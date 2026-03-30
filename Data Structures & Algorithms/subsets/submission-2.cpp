/*
Pattern: BT
Base:
Transition:
Invariant:
*/
class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> candidate={};
        bt(nums,candidate,0);
        return res;        
    }
private:
    void bt(vector<int>& nums, vector<int>& candidate, int idx)
    {
        if(idx>=nums.size()){
            res.push_back(candidate);
            return;
        }
            
        candidate.push_back(nums[idx]);
        bt(nums, candidate,idx+1);
        candidate.pop_back();
        bt(nums, candidate,idx+1);
    }
};
