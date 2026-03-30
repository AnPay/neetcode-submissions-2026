/*
Pattern: Stack
State: stack<int> st
Transition:
push in st if its not +,-,*,/
if(op):
    pop twice, do the op and push back in stack
if(!st.empty())
pop the top
Invariant: ops are never pushed
Complexity: O(n)
Edge case: Empty stack, negative numbers, 0 as number,
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(string s : tokens)
        {
            if(s!="+" && s!="-" && s!="*" && s!="/")
            {
                int num = to_num(s);
                st.push(num);
            }
            else
            {
                int n1 = st.top(); st.pop();
                int n2 = st.top(); st.pop();
                int ans;
                if(s == "+")
                    ans = n1+n2;
                else if(s == "-")
                    ans = n2-n1;
                else if (s =="*")
                    ans = n1*n2;
                else if(s== "/")
                    ans = n2/n1;
                st.push(ans);
            }
            
        }    
        return st.top();
    }
    private:
    int to_num(string s)
    {
        int n =0;
        int idx=0;
        if(s[0]=='-')
            idx=1;
        for(;idx<s.length();idx++)
            {
                n=10*n+s[idx]-'0';
              //  cout<<"q "<<n<<"\n";
            }
        if(s[0]=='-')
            n=n*-1;
        //cout<<n<<"\n";
        return n;
    }
};
