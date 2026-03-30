/* 
Pattern: Prefix length encoding
State: Encoded string builder, pointer
Invariant: Each string is stored as
len#string

Transition:
Encode:
for each string:
append len of string
append#
append string

Decode:
while pointer < encoded.size():
    read digits until '#'
    length = parsed number
    substring(pointer+1, length)
    move pointer forward


Edge cases: "", ##, very long strings
Time complexity: o(n)
Before coding: Force yourself to list:
Empty input: 2 to 1000 
Single element: no 
 */

class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for(string st : strs)
        {
            encoded+=to_string(st.length());
            encoded+="#";
            encoded+=st;
        }   
        return encoded;

    }

    vector<string> decode(string s) {
        int pointer = 0;
        vector<string>res;
        cout<<s<<"\n";
        while(pointer<s.length())
        {
            int len = 0;
           // cout<<pointer<<"p\n";
            while(s[pointer]!='#')
                len =len*10+ s[pointer++]-'0';
           // cout<<len<<"ww\n";
            string temp = s.substr(pointer+1,len);
           // cout<<temp<<"\n";
            res.push_back(temp);
            pointer=pointer+len+1;
        }
        return res;
    }
};
