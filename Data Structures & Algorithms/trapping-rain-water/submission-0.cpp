class Solution {
public:
    int trap(vector<int>& height) {
        int sz = height.size();
        vector<int>leftMax(sz);
        vector<int>rightMax(sz);
        leftMax[0]=height[0];
        rightMax[sz-1]=height[sz-1];
        for(int i =1;i<sz;i++)
        {
            leftMax[i]=max(leftMax[i-1],height[i]);
        }

        for(int i =sz-2;i>=0;i--)
        {
            rightMax[i]=max(rightMax[i+1],height[i]);
        }
        int ans =0;
        for(int i =0;i<sz;i++)
        {
            ans+=min(leftMax[i],rightMax[i])-height[i];
        }
        return ans;
        
    }
};
/*
0,2,0,3,1,0,1,3,2,1
rMax = 1,3,3,7,7,7,7,-1,-1,-1
lMax = -1,1,1,3,3,3,3,3,7,7
*/