class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        int i, j, sum;
        vector<int>res(2);
        for(i=0,j=len-1;i<j;)
        {
            sum = numbers[i]+numbers[j];
            if(sum==target)
                {res[0]=i+1;res[1]=j+1;break;}
            else if(sum<target)
                i++;
            else
                j--;
        } 
        return res;   
    }
};
