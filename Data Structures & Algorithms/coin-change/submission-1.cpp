/*
Pattern: 1D DP | Knapsack style because target amount
State: dp[i] tells min coins to make amount i
Transition: 
for each coin:
    for coin amount x to target:
        dp[x]=min(dp[x],dp[target-x]+1)
Base:
Invariant:
Complexity: O(n*amount)
Edge case: empty vector, very huge amount, 2 coin value summing> 2^31
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int>dp(amount+1,INT_MAX); 
        dp[0]=0;  
        for(int coin : coins)
        {
            for( int curr_amt = coin;curr_amt<=amount;curr_amt++)
            {
                if(dp[curr_amt - coin] != INT_MAX)
                dp[curr_amt]=min(dp[curr_amt],(dp[curr_amt-coin]+1));
            }
        } 
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};
