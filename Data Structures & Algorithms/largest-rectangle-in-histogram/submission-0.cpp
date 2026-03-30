class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        /*
        Always find increasing height -> monotonic stack
        So if current element is lesser than prev elem, pop prev element(use stack)
        In stack, push index and element.
        If curr elem < stack.top(),pop,calculate area possible from that single height
        Keep popping until stack.top()> curr elem
        So up until from here, again you can make a rectangle
        Calc max area =(right boundary-left boundary-1*height if last popped)
        push curr elem, with index as index of last popped elem
        */
        int maxArea =0;
        stack<pair<int,int>> st;
        for(int i =0;i<heights.size();i++)
        {
            int start=i;
            while(!st.empty() && st.top().first>heights[i])
            {
                pair<int,int> hi = st.top();
                maxArea = max(maxArea,(i-hi.second)*hi.first);
                st.pop();
                start = hi.second;
            }
            st.push({heights[i],start});
        }
        while(!st.empty())
        {
            pair<int,int> hi = st.top();
            maxArea = max(maxArea,(int)((heights.size()-hi.second)*hi.first));
            st.pop();
        }
        
        return maxArea;
    }
};
/*
7,1,7,2,2,4


*/