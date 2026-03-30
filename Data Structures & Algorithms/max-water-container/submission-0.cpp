class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res=0;
        int l,r;
        int sz = heights.size();
        l=0;
        r=sz-1;
        while(l<r)
        {
            int width = r-l;
            int minHeight = min(heights[l],heights[r]);
            int area = width*minHeight;
            res = max(res,area);
            if(heights[l]<heights[r])
                l++;
            else
                r--;
        }
        return res;
    }
};
/*
1,7,2,5,4,7,3,6
1,7,7,7,7,7,7,7
7,
*/