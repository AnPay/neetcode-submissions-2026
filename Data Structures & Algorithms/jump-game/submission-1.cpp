class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i=0;
        int goal=nums.size()-1;
        for(i=goal-1;i>=0;i--)
        {
            if(i+nums[i]>=goal)
                goal=i;
        } 
        return goal==0?1:0;   
    }
};
