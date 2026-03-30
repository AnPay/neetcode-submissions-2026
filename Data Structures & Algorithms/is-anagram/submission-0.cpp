class Solution {
public:
    bool isAnagram(string s, string t) {
       //sort both the strings & compare, o(nlogn + n)
       sort(s.begin(),s.end());
       sort(t.begin(),t.end());
       return(s==t); 
    }
};
