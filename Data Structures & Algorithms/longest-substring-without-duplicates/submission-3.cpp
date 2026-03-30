class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     /*
     longest---> Sliding window
     hash to check duplicate

     */   
    int l,r,maxLen;
    l=0;maxLen=0;r=1;
    int len = s.length();
    if(len==0)
        return 0;
    unordered_set<char>seen;
    //seen.insert(s[l]);
    for(int r =0;r<len;r++)
    {
        while(seen.count(s[r]))
        {
            seen.erase(s[l++]);
        }   
        
        seen.insert(s[r]);
        maxLen = max(maxLen, r-l+1);
    }
    return maxLen;
    }
};
