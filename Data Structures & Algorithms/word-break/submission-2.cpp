class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n+1);
        dp[0]=true;  
        unordered_set<string> hash(wordDict.begin(),wordDict.end());  
        for(int i =1;i<=n;i++)
        {
            for(int j =0;j<i;j++)
            {
                //if(dp[j]==true && find(wordDict.begin(),wordDict.end(),s.substr(j,i-j))!=wordDict.end())
                //[0 ........ j-1] | [j ........ i-1]
                //left part         right part
                if(dp[j]==true && hash.find(s.substr(j,i-j))!=hash.end())
                
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
“I use DP where dp[i] represents whether the first i characters can be segmented.
For each i, I try all possible previous cuts j, and if dp[j] is true and substring s[j:i] exists in dictionary, I mark dp[i] as true.”
Pattern: 1d/Partition DP
State: dp[i] = id string from 0 to i-1 is possible or can the first i characters (0 to i-1) be segmented?
Base: dp[0] = true sincelen 0 can be segmented
Transition:
    for(i=1 to n)
        for(j =0 to i)
            if(dp[j] == true && ss from j to i exists in dict)
                dp[i]=1
Complexity: O(n2)
Edge case: input len 0, dict len 0
*/