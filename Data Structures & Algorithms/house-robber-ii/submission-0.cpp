class Solution {
public:
    int rob(vector<int>& nums) {
    int n = nums.size();
    if(n==0)
        return 0;
    if(n==1)  
        return nums[0];
    if(n==2)
        return max(nums[0],nums[1]);
    vector<int>dp0(n);
    vector<int>dp1(n);
    //take 0
    dp0[0]=nums[0];
    dp0[1]=max(dp0[0],nums[1]);
    for(int i=2;i<n-1;i++)
    {
        dp0[i]=max(dp0[i-1],dp0[i-2]+nums[i]);
    }  
    dp1[1]=nums[1];
    dp1[2]=max(nums[1],nums[2]);
    for(int i=3;i<n;i++)
    {
        dp1[i]=max(dp1[i-1],dp1[i-2]+nums[i]);
    }
    return max(dp0[n-2],dp1[n-1]);
    }
};
/*
3,4,3
dp[0]=3;
dp[1]=4;

Now:

House 0 and house n-1 are ALSO adjacent.

So the only new problem is:

You cannot rob both first and last house.

That’s it.
So there are only two valid scenarios:

Case 1:

Rob from index 0 to n-2
(Exclude last house)

Case 2:

Rob from index 1 to n-1
(Exclude first house)

Now both cases are just House Robber I.
*/