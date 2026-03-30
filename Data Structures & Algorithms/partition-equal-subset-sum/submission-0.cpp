class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int n : nums) sum += n;

        if (sum % 2 != 0) return false;

        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : nums) {
            for (int s = target; s >= num; s--) {
                dp[s] = dp[s] || dp[s - num];
            }
        }

        return dp[target];    
    }
};

/*
to be split in 2 parts, 1st condition sum of total elements should be even
if not return false
now target sum is sum/2;
bas after this i cant think how its dp
*/