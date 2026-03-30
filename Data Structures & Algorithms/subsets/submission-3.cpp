/*
Pattern: BT
Base:
Transition:
Invariant: elements before idx are already considered
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
        // if(idx==nums.size())
        //     return;
        res.push_back(candidate);
        for(int i =idx;i<nums.size();i++)
        {
            candidate.push_back(nums[i]);
            bt(nums, candidate,i+1);
            candidate.pop_back();
        }
    }
};
