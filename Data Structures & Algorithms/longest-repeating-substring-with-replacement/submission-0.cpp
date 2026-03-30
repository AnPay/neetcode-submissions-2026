class Solution {
public:
    int characterReplacement(string s, int k) {
    /*
        AABAACAA
        CAABAACAA

    */    
    unordered_map<int, int>HT;
    int l, r, maxLen, maxFreq = 0;
    l=0;maxLen=0;
    int len = s.length();
    for(r=0;r<len;r++)
    {
        HT[s[r]]++;
        maxFreq = max(maxFreq, HT[s[r]]);

        while((r - l + 1) - maxFreq > k)
        {
            HT[s[l]]--;
            l++;
        }
           
        maxLen = max(maxLen,(r-l+1));
    
        
    }
    return maxLen;
    }
};
