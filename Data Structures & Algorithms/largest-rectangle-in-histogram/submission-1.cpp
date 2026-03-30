class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>lmin(n,0);
        vector<int>rmin(n,n-1);
        stack<pair<int,int>>st;
        for(int i =0;i<n;i++)
        {
            if(!st.empty())
            {
                while(!st.empty() && heights[i]<st.top().first)
                {
                    int idx = st.top().second;
                    st.pop();
                    rmin[idx]=i-1;
                }
            }
            
                st.push({heights[i],i});
        }
        while(!st.empty())
        {
            int idx = st.top().second;
            rmin[idx]=n-1;
            st.pop();
        }  

        for(int i =n-1;i>=0;i--)
        {
            if(!st.empty())
            {
                while(!st.empty() && heights[i]<st.top().first)
                {
                    int idx = st.top().second;
                    st.pop();
                    lmin[idx]=i+1;
                }
            }
            
                st.push({heights[i],i});
        }
        while(!st.empty())
        {
            int idx = st.top().second;
            lmin[idx]=0;
            st.pop();
        }   
        for(int i =0;i<n;i++)
        {
            cout<<lmin[i];
        }
        cout<<"\n";
        for(int i =0;i<n;i++)
        {
            cout<<rmin[i];
        }
        int maxArea =0;
        for(int i =0;i<n;i++)
        {
            int area = (rmin[i]-lmin[i]+1)*heights[i];
            maxArea= max(area,maxArea);
        }
        return maxArea;
    }
};
