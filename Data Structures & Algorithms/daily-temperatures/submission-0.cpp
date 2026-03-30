class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>st;
        vector<int>res(temperatures.size());
        for(int i= temperatures.size()-1;i>=0;i--)
        {
            while(!st.empty()&&st.top().first<=temperatures[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                res[i]=st.top().second-i;
            }
            st.push({temperatures[i],i});

        }
        return res;
        
    }
};
/*
30,38,30,36,35,40,28

1,4,1,2,1,  
*/
