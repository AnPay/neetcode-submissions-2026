class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
        So brute force could be, calculate the product of array in O(n)
        and then again do traversal, and divide arrayProd by currEleme to get array prod
        except itself
        But since division operation isnt allowed, we cant do brute force

        We can maintain a leftProdArr and rightProd array which will have prod
        of element on the left side and right side except the curr element
        It will 2O(n)
        For each index, ans = lProdarr*rProdArr
        */
        int size = nums.size();
        vector<int>lProdArr(size);
        vector<int>rProdArr(size);
        lProdArr[0]=1;
        rProdArr[size-1]=1;
        for(int i =1;i<size;i++)
        {
            lProdArr[i]=lProdArr[i-1]* nums[i-1];
        }
        for(int i=size-2;i>=0;i--)
        {
            rProdArr[i]=rProdArr[i+1]*nums[i+1];
        }

        vector<int>res(size);
        for(int i=0;i<size;i++)
            res[i]=lProdArr[i]*rProdArr[i];

        return res;
    }
};
