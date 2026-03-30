class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l =0;
        int r = heights.size()-1;
        int maxarea=0;
        while(l<r)
        {
            int width = r-l;
            int height = min(heights[l],heights[r]);
            int area = width*height;
            maxarea = max(area,maxarea);
            if(heights[l]<heights[r])
                l++;
            else
                r--;
        }    
        return maxarea;
    }
};
