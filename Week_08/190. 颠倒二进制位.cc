class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        uint32_t ans = 0;
        int i = 32;
        while(i--)
        {
            ans = (ans<<1);
            ans= ans + (n&1);
            n= (n >> 1);
            
        }
        return ans;
    }
};