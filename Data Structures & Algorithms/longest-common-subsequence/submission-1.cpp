class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length();
        int len2 = text2.length();
        //dp[i][j] = LCS length using first i chars of text2 and first j chars of text1
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
        //make 1 bigger than 2
        // if(len2>len1)
        // {
        //     int temp = len1;
        //     len1=len2;
        //     len2=temp;
        //     string tmp = text2;
        //     text2=text1;
        //     text1=text2;
        // }
        for(int i =1;i<=len1;i++)
        {
            for(int j=1;j<=len2;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[len1][len2];
    }
};
