class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n+1);
        dp[0]=true;    
        for(int i =1;i<=n;i++)
        {
            for(int j =0;j<i;j++)
            {
                if(dp[j]==true && find(wordDict.begin(),wordDict.end(),s.substr(j,i-j))!=wordDict.end())
                {
                    dp[i]=true;
                    break;
                 }
            }
        }
        return dp[n];
    }
};
/*
so for a string till index i  to be present
if dp[j]= true and string from jto i is present in dict
dp[i]---> string until idx i is also true--> is present in dict
*/