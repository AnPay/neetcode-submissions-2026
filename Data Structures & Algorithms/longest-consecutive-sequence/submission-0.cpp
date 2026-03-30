class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       //Easiest way is to sort but then complexity will be O(nlogn)
       //Can use an array of size=1000, mark the numbers, but oh nums[i] can be 10^9 so this approach will not work
       // 
       unordered_set<int>HT(nums.begin(),nums.end());
       int longest =0;
       for(int num: HT){
        if(HT.find(num-1)==HT.end())
            {
                int length=1;
                while(HT.find(num+length)!=HT.end())
                    length++;
                longest = max(longest,length);
            }

       }
       return longest;
    }
};
