class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    /*
    I think merge sort can help, its O(log(n)) also
    2 arrays are already sorted, if i can merge and then
    find middle elements which will be O(1), it should work

    */    
    int s1=nums1.size();
    int s2=nums2.size();
   
    
    int i=0,j=0,median1=0,median2=0;
    for(int count=0;count<(s1+s2)/2+1;count++)
    {
        median2=median1;
        if(i<s1 && j<s2){
            if(nums1[i]<=nums2[j])
                median1=nums1[i++];
            else if(nums1[i]>nums2[j])
                 median1=nums2[j++];
        }
        else if(i<s1)
            median1=nums1[i++];
        else
            median1=nums2[j++];
    }
    
    int n =s1+s2;
    // for(int k =0;k<n;k++)
    //     cout<<mergedArray[k]<<" ";
    // cout<<"\n";
    if(n%2!=0)
        return median1;
    else
        return ((double)(median1+median2)/2);
    }
};
