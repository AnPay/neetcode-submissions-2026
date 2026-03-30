class Solution {
public:
    int findMin(vector<int> &nums) {
      /*
        3,4,5,6,1,2
        
      */  
      //Check if already sorted i.e. nums[l]<nums[r]
      //else do a binary search
      //here if nums[mid]>=nums[l], it implies left arr is already sorted
      //so our min will lie in right array, so update l=mid+1;
      //else it implies left arr isnt sorted and mil will lie in left side
      //so update r=mid-1
      int size = nums.size();
      int lo =0;
      int hi = size-1;
      
      int res=nums[lo];
      while(lo<=hi)
      {
        if(nums[lo]<nums[hi])
          {
            res=min(res,nums[lo]);
            break;
          }
        int mid = lo +(hi-lo)/2;
        res=min(res,nums[mid]);
        if(nums[mid]>=nums[lo])
          lo=mid+1;
        else
          hi=mid-1;
      }
      return res;
    }
};
