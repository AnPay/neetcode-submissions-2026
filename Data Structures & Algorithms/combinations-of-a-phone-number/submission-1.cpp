/*
Pattern: backtrack
Base: if(idx==digits.length())
State: hash table with num and corresponding chars
Transistion: for length of value, call backtracking
Invariant: At any point, s.length() == idx
Complexity: o(4^n)
Space complexity: O(n)
Edge case: empty, 1
*/
class Solution {
public:
    unordered_map<char, string> HT;
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        
        string s;
        HT['2']="abc";
        HT['3']="def";
        HT['4']="ghi";
        HT['5']="jkl";
        HT['6']="mno";
        HT['7']="pqrs";
        HT['8']="tuv";
        HT['9']="wxyz";
        // for(int i =0;i<HT.size();i++)
        //     cout<<HT[i]<<"\n";
        if(digits.length()==0)
            return {};
        bt(digits, s, 0);
        return res;    
    }
private:
    void bt(string digits, string& s, int idx )
    {
        // for(int i =0;i<HT.size();i++)
        //     cout<<HT[i]<<"\n";
        // cout<<"idx "<<idx<<"\n";
        if(idx == digits.length())
        {
            cout<<"s "<<s<<"\n";
            res.push_back(s);
            return;
        }
        // cout<<digits[idx];
        string val = HT[digits[idx]];
        // cout<<"val "<<val<<"\n";
        for(int i =0;i<val.length();i++)
        {
            s.push_back(val[i]);
            bt(digits,s,idx+1);
            s.pop_back();
        }
    }
};
