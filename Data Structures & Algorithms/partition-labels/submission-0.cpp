class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>hash(26);
        for(int i =0;i<s.size();i++)
        {
            hash[s[i]-'0']=i;
        }    

        int start=0;
        int end =0;
        vector<int> res;
        for(int i =0;i<s.size();i++)
        {
            end = max(end,hash[s[i]-'0']);
            if(i==end)
            {
                int len = end-start+1;
                res.push_back(len);
                start=end+1;
            }

        }
        return res;
    }
};
