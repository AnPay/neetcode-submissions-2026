class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int size = prices.size();
      int l,r,maxP;
      l=maxP=0;
      r = 1;
      while(r<size)
      {
        if(prices[r]>prices[l])
        {
            maxP=max(maxP, prices[r]-prices[l]);
            
        }
        else
            l=r;
        r++;
      }  
      return maxP;
    }
};
