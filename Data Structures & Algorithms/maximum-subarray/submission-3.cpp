class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum = 0;
        int max_so_far =nums[0];
        for(int n : nums)
        {
            if(curr_sum<0)
                curr_sum=0;
            curr_sum+=n;
           
            max_so_far = max(max_so_far,curr_sum);
        }
        return max_so_far;
    }
};
