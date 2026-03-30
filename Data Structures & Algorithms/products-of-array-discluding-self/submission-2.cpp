/*
Pattern: Prefix/Suffix product
State:
prefix[i] : product of preifx before i
suffix[i] : product of suffix after i
Transition:
prefix[i] = prefix[i-1] * nums[i-1]
suffix[i] = suffix[i+1] * nums[i+1]
ans [i]= prefix[i]*suffix[i]

Edge cases: 0 element, many elements near maximum value
Time complexity: o(n)

Before coding: Force yourself to list:
Empty input: 2 to 1000
Single element: no
All equal: will work
Strictly increasing/decreasing: will work
Negative numbers: will work
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftProd(n,1);
        vector<int>rightProd(n,1);
        for(int i=1;i<n;i++)
        {
            leftProd[i]=leftProd[i-1]*nums[i-1];
        }
        for(int i=n-2;i>=0;i--)
        {
            rightProd[i]=rightProd[i+1]*nums[i+1];
        }
        vector<int> res(n);
        for(int i =0;i<n;i++)
        {
            res[i]=leftProd[i]*rightProd[i];
        }
        return res;
    }
};
