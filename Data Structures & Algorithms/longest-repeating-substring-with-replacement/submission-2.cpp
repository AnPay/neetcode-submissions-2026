class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>HT;
        int maxfreq=0;
        int l,r;
        l=r=0;
        int len=0;
        while(r<s.length())
        {
            HT[s[r]]++;
            
            maxfreq = max(maxfreq,HT[s[r]]);

            while((r-l+1 - maxfreq)>k)
            {
                HT[s[l]]--;
                l++;
            }
           
            
           
            len = max(len,r-l+1);
            r++;
        }
        return len;
        
    }
};
