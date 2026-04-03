class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int nxor=0;
        int size = nums.size();
        for(int i =1;i<=size;i++)
            nxor=nxor^i;
        for(int n :nums)
            nxor=nxor^n;
        return nxor;

    }
};
