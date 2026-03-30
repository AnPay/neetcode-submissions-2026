/*
Pattern: Recursion with count
State: stack<char
Base case: opne==0 && close==0
Transition: if(open>0)append '(' if(close>open) append')'
Invariant: opening brackets <= closing brackets
Complexity: o(n2)
Edge case: empty string
*/
class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        dfs(n,n,""); 
        return res;   
    }
private:
    void dfs(int open,int close, string s)
    {
        if(open==0 && close ==0) 
        {
            res.push_back(s);
            return;
        }
        if(open>0 )
            dfs(open-1, close,s+'(');
        if(close>open)
            dfs(open,close-1,s+')');
    }
};
