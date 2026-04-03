//0100 0111
class Solution {
public:
    int getSum(int a, int b) {
        int res=0;
        int carry =0;
        int mask = 0xFFFFFFFF;
        for(int i =0;i<32;i++)
        {
            int bita = (a>>i)&1;
            int bitb = (b>>i)&1;
            int sum_bit = bita^bitb^carry;
            carry = (bita + bitb + carry ) >=2 ?1:0;
            if(sum_bit)
                res=res|(1<<i);
        }  
        //If the result represents a negative number in 32-bit two's complement:
        if (res > 0x7FFFFFFF) {
            res = ~(res ^ mask);
        }

        return res; 
    }
};
