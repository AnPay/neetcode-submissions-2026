class Solution {
public:
    bool isValid(string s) {
      /*
        Use stack to push every opening bracket
        If closing bracket,check if bracket on top is corresponding
        opening bracket
        if yes, pop, else return false
        at the end of string, if stack is empty return true
        else return false
      */  
      stack<char> st;
      int len = s.length();
      for(int i =0;i<len;i++)
      {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            st.push(s[i]);
        else{
            if( s[i]==')')
            {
                if(!st.empty() && st.top()=='(')
                    st.pop();
                else
                    return false;
            }
            else if(s[i]=='}')
            {
                if(!st.empty() && st.top()=='{')
                    st.pop();
                else
                    return false;
            }
            else if(s[i]==']')
            {
                if(!st.empty() && st.top()=='[')
                    st.pop();
                else
                    return false;
            }
        } 
      }
      return st.empty();
    }
};
