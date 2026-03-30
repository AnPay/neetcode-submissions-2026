class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
    /*
        max k =max(piles)
        lo =0;hi=k
        mid=lo+hi/2
        check if mid is fine
        if no of hours needed with rate mid, H <h
        ans=found and increase lo, mid+1
        else
        decrease hi=mid-1
        return ans
    */
    int maxBanana=0;
    for(int b : piles)
        maxBanana = max(maxBanana,b);    
    int lo = 1;  //be mindful
    int hi = maxBanana;
    int ans=0;
    while(lo<=hi)
    {
        int mid = lo + (hi-lo)/2;  //tentative banana eating rate
        //check if with this rate all bananas can finish within h hours
        int rh=0;
        for(int b :piles)
        {   
            //totalTime += ceil(static_cast<double>(p) / k);        
            rh += (b + mid - 1LL) / mid;  //the expression (b + mid - 1) / mid is a standard "trick" to perform ceiling division using only integer arithmetic.
        }
        if(rh<=h)
        {            
            ans = mid;
            hi=mid-1;
            
        }
        else if(rh>h)
            lo=mid+1;

    }
    return ans;
    }
};
