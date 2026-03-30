class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>st;
        vector<int>res(temperatures.size());
        for(int t =0;t<temperatures.size();t++)
        {
            int idx=t;
            if(!st.empty())
            {
                //int temp = st.top().first;
               
                while(!st.empty()&& temperatures[t]>st.top().first )
                {
                    int idx2= st.top().second;
                    res[idx2]=t-idx2;
                    st.pop();
                   // temp=st.top().first;
                    //t++;
                }
            }
            st.push({temperatures[idx],idx});
        }  
        while(!st.empty())
        {
            int idx = st.top().second;
            res[idx]=0;
            st.pop();
        }  
        return res;
    }
};
/*
28 0
40  0
- 35 1
- 36 2
- 30 1
- 38 3
-30  1
*/