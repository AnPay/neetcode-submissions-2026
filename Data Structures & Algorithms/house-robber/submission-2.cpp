class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(nums.empty())
            return 0;
        if(nums.size()==1)
            return nums[0];
        vector<int>dp(nums.size());
     
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        
        for(int i=2;i<nums.size();i++)
        {
           
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }    
        return dp[n-1];
    }
};
/*
dp[0]=2;
dp[1]=9;
dp[2]=10;
dp[3]=12;
dp[4]=16
*/
