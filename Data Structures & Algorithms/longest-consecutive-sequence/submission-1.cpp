/*
Pattern: Hashset, alows o(1) lookup
State:
unordered_set<int> hash(nums.begin(),nums.end());
current
Invariant: nums[num-1] must not exist
Transition:
for each num in nums:
    check if num-1 exists
    if doesnt exists:
        start a new seq
        curr = num
        len =0
        while(curr+1 exists)
            len++
        update maxlen

Edge cases:
empty vector, duplicate elements, large gaps,negative numbers
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash(nums.begin(),nums.end());
        int maxlen=0;
        for(int num : hash)
        {
            if(hash.count(num-1)==0)
            {
                int curr = num;
                int len =1;
                while(hash.count(curr+1)>0)
                {
                    len++;
                    curr++;
                }
                maxlen = max(len,maxlen);
            }
        }
        return maxlen;
    }
};
