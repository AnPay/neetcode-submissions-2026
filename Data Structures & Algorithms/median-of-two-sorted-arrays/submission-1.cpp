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
    vector<int> mergedArray(s1+s2);
    int index=0;
    int i,j;
    for(i=0,j =0;i<s1&&j<s2;)
    {
        if(nums1[i]<=nums2[j])
            mergedArray[index++]=nums1[i++];
        else if(nums1[i]>nums2[j])
            mergedArray[index++]=nums2[j++];
    }
    while(i<s1){
        mergedArray[index++]=nums1[i++];
    }
    while(j<s2){
        mergedArray[index++]=nums2[j++];
    }
    int n =s1+s2;
    // for(int k =0;k<n;k++)
    //     cout<<mergedArray[k]<<" ";
    // cout<<"\n";
    if(n%2!=0)
        return mergedArray[n/2];
    else
        return ((double)(mergedArray[n/2]+mergedArray[n/2-1])/2);
    }
};
