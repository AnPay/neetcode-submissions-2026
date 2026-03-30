class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l =0;
        int r=0;
        unordered_map<char,int>HT;
        int maxLen =0;
        if(s.length()==0)
        return 0;
        while(r<s.length())
        {
            HT[s[r]]++;
            while(HT[s[r]]>1)
            {
                HT[s[l]]--;
                l++;
            }
            maxLen = max(maxLen, (r-l)+1);
            r++;
          
        }
        return maxLen;
        
    }
};
