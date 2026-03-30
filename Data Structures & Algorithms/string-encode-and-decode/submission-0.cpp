class Solution {
public:

    string encode(vector<string>& strs) {
        
        if (strs.empty())
            return "";
        // for(string s : strs)
        //     cout<<s;
        vector<int>sizes;
        for(auto s : strs)
            sizes.push_back(s.size());

        string encodedString  = "";
        for(int sz : sizes)
            encodedString+=to_string(sz)+',';

        encodedString+="#";

        for(auto s : strs)
            {
                encodedString+=s;
            }
        //cout<<encodedString;
        return encodedString;
    }

    vector<string> decode(string s) {
        if(s.empty())
            return {};
        vector<string> decodedString;
        vector<int>sizes;
        int i=0;
        while(s[i]!='#')
        {
            //cout<<"i "<<i<<"\n";
            string curr = "";
            while(s[i]!=',')
            {
                curr+=s[i];
                i++;
            }
            sizes.push_back(stoi(curr));
            i++;
        }
        i++;
        for(int sz : sizes)
        {
            decodedString.push_back(s.substr(i,sz));
            i+=sz;
        }
        return decodedString;
        
    }
};
