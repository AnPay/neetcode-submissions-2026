class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int>res(size,0);
        stack<int> st;

        for(int i =0;i<size;i++)
        {
            int t = temperatures[i];
            while(!st.empty()&& temperatures[st.top()]<t)
            {
                int index = st.top();
                st.pop();
                res[index]=i-index;
            }
            st.push(i);
        }    
        return res;
    }
};
