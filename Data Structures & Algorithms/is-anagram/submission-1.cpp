class Solution {
public:
    bool isAnagram(string s, string t) {
       //sort both the strings & compare, o(nlogn + n)
    //    sort(s.begin(),s.end());
    //    sort(t.begin(),t.end());
    //    return(s==t); 
    //hash and compare, 
        if(s.length()!=t.length())
            return false;
        unordered_map<char,int> sHT;
        unordered_map<char,int> tHT;
        for(int i =0;i<s.length();i++)
        {
            sHT[s[i]]++; 
            tHT[t[i]]++;    
        }
        return sHT==tHT;
    }
};
