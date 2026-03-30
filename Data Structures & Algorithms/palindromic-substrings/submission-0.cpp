class Solution {
public:
    int countSubstrings(string s) {
        int count =0;
        int n = s.length();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i =0;i<n;i++)
            {
                dp[i][i]=1;
                count++;
            }
        for(int len = 2;len<=n;len++)
        {
            for(int i =0;i<=n-len;i++)
            {
                int j = i+len-1;
                if(s[i]==s[j])
                {
                    if(len==2 || dp[i+1][j-1])
                    {
                        dp[i][j]=1;
                        count++;
                    }
                }
            }
        }    
        return count;
    }
};
