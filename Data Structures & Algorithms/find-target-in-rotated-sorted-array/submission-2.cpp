class Solution {
public:
    int binarySearch(vector<int>& nums, int target,int lo, int hi)
    {
        while(lo<=hi)
        {
            int mid = lo +(hi-lo)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
            {
                lo=mid+1;
            }
            else
                hi=mid-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        //find pivot
        int lo =0;
        int hi = nums.size()-1;
        int pivot;
        while(lo<hi)
        {
            int mid = lo +(hi-lo)/2;
            if(nums[mid]>nums[hi])
                lo=mid+1;
            else
                hi=mid;
                
        }    
        pivot = lo;
        int res = binarySearch(nums, target,0,pivot);
        if(res!=-1)
            return res;
        else
            return binarySearch(nums,target,pivot,nums.size()-1);
    }

};
