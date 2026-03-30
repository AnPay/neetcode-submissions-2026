class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    /*

    */    
    vector<int>dp(amount+1,amount+1);
    dp[0]=0;
    for(int x =1;x<=amount;x++)
    {
        for(int i =0;i<coins.size();i++)
        {
            int c = coins[i];
            if(x-c>=0)
                dp[x] = min(dp[x-c]+1,dp[x]);
        }
    }
    return dp[amount]>amount?-1:dp[amount];
    }
};
