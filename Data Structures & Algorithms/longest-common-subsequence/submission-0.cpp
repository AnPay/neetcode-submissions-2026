/*
Pattern: 2D DP on string
State: dp[i][j] represents LCS for suffix of text1 starting from i and
suffix of text2 starting from j
Transition: 
if(text1[i]==text2[j])
    dp[i][j]=1+dp[i+1][j+1]
else
    dp[i][j]=max(dp[i+1][j],dp[i][j+1])
Invariant: dp[i][j] always stores the
correct LCS length for suffixes text1[i:] and text2[j:]
Edge case: empty string
Complexity: O(len1*len2)
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length();
        int len2 = text2.length();
        vector<vector<int>>dp(len1+1,vector<int>(len2+1,0));
        for(int i =len1-1;i>=0;i--)
        {
            for(int j =len2-1;j>=0;j--)
            {
                if(text1[i]==text2[j])
                    dp[i][j]=1+dp[i+1][j+1];
                else
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }    
        return dp[0][0];
    }
};
