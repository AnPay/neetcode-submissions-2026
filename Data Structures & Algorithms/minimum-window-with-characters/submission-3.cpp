class Solution {
public:
    string minWindow(string s, string t) {
    unordered_map<char,int>HT_t;
    unordered_map<char,int>HT_s;
    int present=0;
   
    int l,r;
    l=r=0;
    int len=INT_MAX;//s.length();
    // if(needed>len)
    //     return "";
    int startIdx=0;
    int endIdx=0;
    for(char ch : t)
        HT_t[ch]++;
    int needed = HT_t.size();
    while(r<s.length())
    {
        HT_s[s[r]]++;
        if(HT_t.count(s[r]) && HT_s[s[r]]==HT_t[s[r]])
        {
            present++;
        }
        while(present==needed)
        {
            if(len>= (r-l+1))
            {
                len = r-l+1;
                startIdx = l;
                endIdx = r;
            }
            
            if (HT_t.count(s[l]) && HT_s[s[l]] == HT_t[s[l]])
            {
                present--;
            }
            HT_s[s[l]]--;
            l++;
        }
        
        r++;
        
    }   
    if (len==INT_MAX)
        return "";
    string res= s.substr(startIdx, (endIdx-startIdx+1));
    return res;
    }
};
