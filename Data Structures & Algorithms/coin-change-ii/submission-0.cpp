class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int>dp(amount+1,0);
        dp[0]=1;
        for(int n:coins)
        {
            for(int j =n;j<=amount;j++)
                dp[j]+=dp[j-n];
        }    
        return dp[amount];
    }
};
