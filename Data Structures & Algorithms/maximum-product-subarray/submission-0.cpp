class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int>dpmax(n,INT_MIN);
        vector<int>dpmin(n,INT_MAX);
        dpmax[0]=nums[0];
        dpmin[0]=nums[0];
        int ans=nums[0];
        for(int i =1;i<n;i++)
        {
            dpmax[i]=max(max(nums[i],nums[i]*dpmax[i-1]),max(nums[i]*dpmax[i-1],nums[i]*dpmin[i-1]));
            dpmin[i]=min(min(nums[i],nums[i]*dpmin[i-1]),min(nums[i]*dpmax[i-1],nums[i]*dpmin[i-1]));
            ans = max(ans,dpmax[i]);
        }
        return ans;
    }
};
/*
We only need:

Maximum product of subarray ending at i

Not starting at i.
Not going to n.
Just ending at i.
*/