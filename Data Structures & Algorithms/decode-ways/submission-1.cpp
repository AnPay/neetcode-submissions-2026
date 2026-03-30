class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n==0 || s[0]=='0')
            return 0;
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i =2;i<=n;i++)
        {
            //singledigit
            if(s[i-1]!='0')
                dp[i]+=dp[i-1];
            //2 digits
            int num = (s[i-2] - '0') * 10 + (s[i-1] - '0');
            if(num>=10 && num<=26)
            {
                dp[i]+=dp[i-2];
            }
        } 
        return dp[n];  
    }
};
/*
first of all i need a map/hash of number to character
generate all possible sets of numbers from given string
return count of sets generated

now challenge is how to generate different arrangements of numbers
if its 123, i can take 1 or leave 1
so it will be 1, 23 or 12,3
i can take 2 or leave 2
so it will be
1,2,3

*/