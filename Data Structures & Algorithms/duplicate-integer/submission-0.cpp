class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> HT;
        for(int i =0;i<nums.size();i++)
        {
            if(HT.find(nums[i])!=HT.end())
                return true;
            else
            {
                HT[nums[i]]=1;
            }
        }
        return false;
    }
};