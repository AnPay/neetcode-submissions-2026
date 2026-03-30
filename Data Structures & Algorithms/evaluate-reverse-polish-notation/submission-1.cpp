class Solution {
public:
//tokens=["4","13","5","/","+"]
    
    int evalRPN(vector<string>& tokens) {
        stack<int>st1;
        for(const string& c : tokens)
        {  
            if(c=="*")
            {
                int n1 = st1.top();st1.pop();
                int n2 = st1.top();st1.pop();
                
                st1.push(n1*n2);
            }
            else if(c=="+")
            {
                int n1 = st1.top();st1.pop();
                int n2 = st1.top();st1.pop();
                st1.push(n1+n2);    
            }
            else if(c=="-")
            {
                int n1 = st1.top();st1.pop();
                int n2 = st1.top();st1.pop();
                st1.push(n2-n1);    
            }
            else if(c=="/")
            {
                int n1 = st1.top();st1.pop();
                int n2 = st1.top();st1.pop();
                st1.push(n2/n1);    
            }  
            else
            {
                st1.push(stoi(c));
            }
               
        }
        return st1.top();
    }
};
