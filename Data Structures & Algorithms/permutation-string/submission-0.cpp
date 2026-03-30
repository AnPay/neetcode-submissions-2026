class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      unordered_map<char,int>HT1;
      unordered_map<char,int>HT2;
      for (char ch : s1  )
        HT1[ch]++;

      int l,r;
      l=0;
      int len1=s1.length();
      for(int r=0;r<s2.length();r++)
      {
        HT2[s2[r]]++;
        if(r-l+1==len1)
        {
            if(HT1==HT2)
                return true;
        
            else
            {
                HT2[s2[l]]--;
                if(HT2[s2[l]]==0)
                    HT2.erase(s2[l]);
                l++;
            }
        }
      }
      return false;
    }
};
