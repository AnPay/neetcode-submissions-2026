class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        vector<vector<int>>dp(len1+1,vector<int>(len2+1,0));
        
        for(int i =0;i<=len1;i++)
        {
            for(int j =0;j<=len2;j++)
            {
                if(i==0)
                    dp[i][j]=j;  //if word1 is 0 j inserts required
                else if(j==0)
                    dp[i][j]=i;  //if word2 is 0 i deletes required
                else{    
                if(word1[i-1]==word2[j-1])
                    dp[i][j]=dp[i-1][j-1];   //Strings are 0-indexed, but DP is built on lengths.
                else
                    dp[i][j] = (1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])));
                }
            }
        }
        return dp[len1][len2];
        
        
    }
};
/*
if word1[i]!=word[i]
either delete,replace or add char at word2[i]
return min steps
Pattern:2D DP
State: dp[i][j] represents number of ways to make word1 until i equals to word2 until j
TRansition:
for(int i to word1.size)
    for(int j =0 to word2.size)
        dp[i][j]= if(word1[i]==word2[j])?dp[i-1][j-1]:
                  1+min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])
Complexity: O(n*m)  
*/