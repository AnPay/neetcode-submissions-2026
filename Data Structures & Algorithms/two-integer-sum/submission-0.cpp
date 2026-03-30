class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>HT;
        for(int i =0;i<nums.size();i++)
        {
            int diff = target-nums[i];
            if(HT.find(diff)!=HT.end())
                return {HT[diff],i};
            else
                HT.insert({nums[i],i});
        }
        return {};
    }
};
