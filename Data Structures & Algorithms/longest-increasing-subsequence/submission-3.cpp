/*
Pattern: 2D DP, String matching
Base : dp[i] represents LIS until index i
State: dp[i]
Transition:
for i=0 to n
for j = 0 to i
if(num[i]>num[j])
dp[i]=max(dp[i],dp[j]+1)
maintai max ans
Complexity: O(n2)
Edge case: negative numbers, 
i j         dp[i]
0            1
1 0          1
2 0,1        2
3 0,1,2      2
4 0,1,2,3    3
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),1);
        int ans =1;
        for(int i =0;i<nums.size();i++)
        {
            for(int j =0;j<i;j++)
            {
                if(nums[i]>nums[j])
                    dp[i]=max(dp[i],dp[j]+1);
                
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
