class Solution {
public:
    string minWindow(string s, string t) {
      if(t.empty() || s.empty())
        return "";

      vector<int>targetCount(128,0); //for all 128ASCII chars since input has capital letters
      
      for(char ch : t)
        targetCount[ch]++;

      int l =0;
      int r;
      int minLength=INT_MAX;
      int required = t.length();  //target chars
      int startIdx;
      for(r =0;r<s.length();)
      {
        if(targetCount[s[r]]>0)  //target char found in curr string
          required--;
        targetCount[s[r]]--;  //decrease the counter in our map, negative means extra char
        r++;
        while(required==0)   //once all chars present, shrink the window
        {
          if(r-l<minLength)
          {
            minLength =r-l;  //update min length
            startIdx=l;
          }
          targetCount[s[l]]++; //add char back to our map
          
          if (targetCount[s[l]] > 0) //>0 means char is missing in the window now
          {
            required++;
          }
          l++;
        }
       
        
      }
      return (minLength == INT_MAX?"":s.substr(startIdx,minLength));
      //return res;
    }
};
