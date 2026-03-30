class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> HT;
        for(int i =0;i<nums.size();i++)
        {
            if(HT.count(nums[i]))
                return true;
            else
            {
                HT.insert(nums[i]);
            }
        }
        return false;
    }
};