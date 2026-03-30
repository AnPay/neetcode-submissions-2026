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

What if the input size is extremely large (billions)?
Sorting approach: O(n log n)
Set approach: O(n)
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(),nums.end()); //numSet is better name than hash
        int maxlen=0;
        for(int num : numSet)
        {
            if(numSet.count(num-1)==0)
            {
                int curr = num;
                int len =1;
                while(curr != INT_MAX && numSet.count(curr+1)>0)  //curr != INT_MAX better to add
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
