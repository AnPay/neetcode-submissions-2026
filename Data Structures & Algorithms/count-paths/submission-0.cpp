/*
Pattern: Graph traversal
State: queue<pair<int,int>> q
Transition:
q.push({0,0})
while(!q.empty)
{
    start - q.front();q.pop();
    if(start==end)
        ans++;
    for down and right valid coords
        push in q
}
return ans;
Invariant: only right and down movement
Edge case: 

Analysis is wrong, uSe 2D DP
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
    vector<vector<int>>dp(m,vector<int>(n,1)); 
    for(int i =1;i<m;i++)
    {
        for(int j=1;j<n;j++)
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
    }   
    return dp[m-1][n-1];
    }
};
