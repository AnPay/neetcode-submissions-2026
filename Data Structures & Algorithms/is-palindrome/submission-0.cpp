class Solution {
public:
    bool isPalindrome(string ss) {
       int len = ss.length();
       char s[len];
       int idx =0;
       for(int i =0;i<len;i++)
       {
        if((tolower(ss[i])>='a' && tolower(ss[i])<='z') || (ss[i]>='0' && ss[i]<='9'))
            s[idx++]=tolower(ss[i]);
       }
    //    cout<<ss<<"\n";
    //    cout<<s<<"\n";
       //len = s.length();
       for(int i =0,j=idx-1;i<j;) 
       {
        // cout<<s[i]<<" "<<s[j]<<"\n";
        
        if(s[i]==s[j])
        {
            i++;j--;
        }
        else
            return false;
       }
       return true;
    }
};
