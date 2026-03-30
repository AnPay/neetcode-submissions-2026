class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i =0;i<n;i++)
            dp[i][i]=1;
        int start=0;
        int maxlen = 1;
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
                        start = i;
                        maxlen = max(len,maxlen);
                    }    
                }
            }
        }
        return s.substr(start,maxlen);
    }
};
/*
    0   a   b   a   b   d
  0 0   0   0   0   0   0 
  a 0   1   1   2   2   2
  b 0   0   1   1   3   3   
  a 0   0   0   1   1   1
  b 0   0   0   0   1   1
  d 0   0   0   0   0   1

this is wrong , its LCS

        a   b   a   b   d
    a   1   0   1   0   0
    b       1   0   1   0
    a           1   0   0
    b               1   0
    d                   1

    We want:

Track longest length

Track starting index
For it to be palindrome:

Characters at ends must match
s[i] == s[j]

The inside part must also be palindrome
That inside is:

s[i+1 .. j-1]
*/