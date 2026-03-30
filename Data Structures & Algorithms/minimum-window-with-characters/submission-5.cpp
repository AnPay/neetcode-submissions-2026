/*
Pattern: Sliding Window
State: unordered_map<char,int> need
int have
int needcount=need.size()
Transition:
l=0, r=0;
increase r/window size until have<need
Shrink window/increase l until have==need
Invariant: have==need(another invariant for SW is window_size>k)
Complexity: O(n)
Edge case:  empty strings, no substring possible, very large string,
t is longer than s
*/
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
        //if char is present in t and freq in s and t also matches
        if(HT_t.count(s[r]) && HT_s[s[r]]==HT_t[s[r]])  
        {
            present++;
        }
        while(present==needed)
        {
            //if curr len > curr window
            if(len>= (r-l+1))
            {
                //update
                len = r-l+1;
                startIdx = l;
                endIdx = r;
            }
            
            //if condition isnt met, stop shrinking
            if (HT_t.count(s[l]) && HT_s[s[l]] == HT_t[s[l]])
            {
                present--;
            }
            HT_s[s[l]]--;
            //shrink window
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
