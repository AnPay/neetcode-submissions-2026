class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> HT;
        for(int a: nums)
        {
            if(HT.count(a))
                return true;
            HT.insert(a);
        }
        return false;
    }
};