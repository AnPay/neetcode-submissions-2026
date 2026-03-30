class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total=0;
        for(int n :nums)
            total+=n;
        int s = (total+target)/2;
        if((total+target)%2!=0 || target > total)
            return 0;
        vector<int>dp(s+1,0);  //number of ways to make sum
        dp[0]=1;
        for(int n :nums)
        {
            for(int j=s;j>=n;j--)
            {
                dp[j]+=dp[j-n];
            }
        }
        return dp[s];
    }
};
/*
Positive group → sum = P
Negative group → sum = N
P+N=target
P-N=total sun
2P=target+total_sum
P=(target+total_sum)/2
So now we need to find if a subset with sum P exists or not
Use dp to find if sum P is possible or not
Pattern:
State:dp[i] represent if sum i is true or false
Transition:
for(int n :nums)
    for(int j =P;j>=n;j++)
        dp[j]+=dp[j-n]
*/
