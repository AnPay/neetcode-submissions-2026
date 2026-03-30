class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int>maxHeap;
    for(int n : nums)
    {
        maxHeap.push(n);
    }    
    int ans;
    for(int i =0;i<k;i++)
    {
        ans = maxHeap.top();
        maxHeap.pop();
    }
    return ans;
    }
};
