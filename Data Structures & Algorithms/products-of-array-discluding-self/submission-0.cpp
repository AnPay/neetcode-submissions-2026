class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        vector<int>lSum(sz);
        vector<int>rSum(sz);
        vector<int> res(sz);
        lSum[0]=1;
        rSum[sz-1]=1;
        for(int i =1;i<sz;i++)
        {
            lSum[i]=lSum[i-1]*nums[i-1];
           
        }
        for(int i =sz-2;i>=0;i--)
        {
            rSum[i]=rSum[i+1]*nums[i+1];
           
        }
        for(int i =0;i<sz;i++)
        {
            res[i]=lSum[i]*rSum[i];
        }
        return res;
    }
};
/*
1,2,4,6
1,1,2,8
48,24,6,1
48,24,12,8

-1,0,1,2,3
1,-1,0,0,0
0, 6 ,6 ,3,1
0,-6,0,0,0
*/
