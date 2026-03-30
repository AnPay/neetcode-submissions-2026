class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> minCost(cost.size()+1);
        int n = cost.size(); 
        minCost[0]=0;
        minCost[1]=0;

        for(int i =2;i<=n;i++)
        {
            minCost[i]=min(minCost[i-1]+cost[i-1],minCost[i-2]+cost[i-2]);
        }
        return minCost[n];  
    }
};
