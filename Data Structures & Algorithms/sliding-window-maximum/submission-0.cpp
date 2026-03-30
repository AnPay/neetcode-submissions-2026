class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>heap;
        priority_queue<pair<int,int>> heap;
        vector<int>res;
        for(int n=0;n<nums.size();n++)
        {
            heap.push({nums[n],n});
            if(n>=k-1)
            {
               // int t = n/3+3;
                while(heap.top().second <= n - k)
                {
                    heap.pop();
                }
                res.push_back(heap.top().first);
                //heap.pop();
                
            }
    
        }    
        return res;
    }
};
